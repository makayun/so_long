/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:45:11 by mmakagon          #+#    #+#             */
/*   Updated: 2023/10/30 11:41:44 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_read(t_map *map, char *filename)
{
	size_t	i;
	int		fd;

	map->map = (char **)ft_calloc((map->blocks_y) + 1, sizeof(char *));
	if (!map->map)
		return (MLX_ERROR);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free (map->map), MLX_ERROR);
	i = 0;
	while (i < map->blocks_y)
		map->map[i++] = get_next_line(fd, 0);
	return (0);
}

int check_walls(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map->map[0][i] && map->map[map->blocks_y - 1][i])
		if (map->map[0][i] != '1' || map->map[map->blocks_y - 1][i++] != '1')
			return (MLX_ERROR);
	while (j < map->blocks_y)
		if (map->map[j][0] != '1' || map->map[j++][map->blocks_x - 1] != '1')
			return (MLX_ERROR);
	return (0);
}

int	map_init(t_map *map, char *filename)
{
	if (map_read(map, filename) == MLX_ERROR)
	{
		ft_printf("Map reading error");
		return (MLX_ERROR);
	}
	if (check_walls(map) == MLX_ERROR)
	{
		ft_printf("Check the walls on your map!");
		return (MLX_ERROR);
	}
	ft_printf("Map OK\n");
	return (0);
}
