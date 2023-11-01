/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:45:11 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/01 14:38:24 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_read(t_map *map, char *filename)
{
	int		i;
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
	close(fd);
	return (0);
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

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

void	find_p_and_c(t_data *data)
{
	t_position	pos;

	data->player.victory = false;
	data->player.collectibles = 0;
	pos.y = 0;
	while (pos.y < data->map.blocks_y)
	{
		pos.x = 0;
		while (pos.x < data->map.blocks_x)
		{
			if (data->map.map[pos.y][pos.x] == 'P')
			{
				data->player.pos.x = pos.x;
				data->player.pos.y = pos.y;
			}
			else if (data->map.map[pos.y][pos.x] == 'C')
				data->player.collectibles += 1;
			pos.x++;
		}
		pos.y++;
	}
}

int	map_init(t_data *data, char *filename)
{
	if (map_read(&data->map, filename) == MLX_ERROR)
	{
		ft_printf("Map reading error");
		return (MLX_ERROR);
	}
	if (check_walls(&data->map) == MLX_ERROR)
	{
		ft_printf("Check the walls on your map!");
		return (map_free(&data->map), MLX_ERROR);
	}
	find_p_and_c(data);
	if (is_there_the_way(data) == MLX_ERROR)
		return (map_free(&data->map), MLX_ERROR);
	ft_printf("Map OK\n");
	return (0);
}
