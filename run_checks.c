/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:35:24 by mmakagon          #+#    #+#             */
/*   Updated: 2023/10/16 15:37:39 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    check_input(int argc)
{
    if (argc <= 1)
    {
        ft_printf("Please, choose any map and try again");
        exit (MLX_ERROR);
        return (MLX_ERROR);
    }
    else if (argc > 2)
    {
        ft_printf("Too much arguments, try again!");
        exit (MLX_ERROR);
        return (MLX_ERROR);
    }
    else
        return (0);
}

int	check_map_height(t_map *map, char *filename)
{
	int		fd;
	char	*line;

	map->blocks_y = 0;
	fd = open (filename, O_RDONLY);
	while ((line = get_next_line(fd, 1)))
		map->blocks_y++;
	close (fd);
	free (line);
	if (map->blocks_y <= 2)
	{
		ft_printf ("The map has too few lines, please try another one");
		exit (MLX_ERROR);
		return (MLX_ERROR);
	}
	return (0);
}

int	check_map_width (t_map *map, char *filename)
{
	int			fd;
	size_t		i;
	size_t		lenght;

	i = 0;
	lenght = 0;
	map->map = ft_calloc((map->blocks_y + 1), sizeof(char *));
	fd = open (filename, O_RDONLY);
	map->map[i] = get_next_line(fd, 0);
	lenght = ft_strlen (map->map[i]);
	while (++i < map->blocks_y || (map->map[i]))
	{
		map->map[i] = get_next_line(fd, 0);
		if (lenght != ft_strlen (map->map[i]))
			return (MLX_ERROR);
		lenght = ft_strlen (map->map[i]);
	}
	map->blocks_x = lenght;
	close(fd);
	return (0);
}

void	run_checks(int argc, t_map *map, char *filename)
{
	check_input (argc);
	check_map_height (map, filename);
	if ((check_map_width (map, filename)) == MLX_ERROR)
	{
		ft_printf ("Please, check that all lines in the map have the same lenght!");
		map_free(map);
	}
	if (map->blocks_x * BLOCK_SIDE > WIDTH || map->blocks_y * BLOCK_SIDE > HEIGHT)
	{
		ft_printf ("The map is too big, please try another one");
		map_free(map);
	}
}