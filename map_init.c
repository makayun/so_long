/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:45:11 by mmakagon          #+#    #+#             */
/*   Updated: 2023/10/24 16:13:03 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	map_read(t_map *map, char *filename)
{
	int		fd;
	size_t	i;

	map->map = (char **)ft_calloc((map->blocks_y) + 1, sizeof(char *));
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < map->blocks_y)
		map->map[i++] = get_next_line(fd, 0);
	close (fd);
	return (0);
}

int	check_map_content(t_map *map)
{
	size_t		j;
	char		line[map->blocks_x];

	j = 0;
	ft_strcpy(line, map->map[0]);
	while (line[j])
		if (line[j++] != '1')
			return (MLX_ERROR);	
	j = 0;
	ft_strcpy(line, map->map[(map->blocks_y) - 1]);
	while (line[j])
		if (line[j++] != '1')
			return (MLX_ERROR);
	return (0);
}

int	map_init(t_map *map, char *filename)
{
	int		fd;
	char	*whole_map;

	whole_map = (char *)ft_calloc(map->blocks_x * map->blocks_y + 1, sizeof(char));
	fd = open("./map1.ber", O_RDONLY);
	read (fd, whole_map, map->blocks_x * map->blocks_y);
	if (!ft_strchr(whole_map, '0') || !ft_strchr(whole_map, '1')
		|| !ft_strchr(whole_map, 'C'))
		return (free(whole_map), MLX_ERROR);
	free(whole_map);
	map_read(map, filename);
	check_map_content(map);
	close (fd);
	return (0);
}
