/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:35:24 by mmakagon          #+#    #+#             */
/*   Updated: 2023/10/24 15:45:27 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_input(int argc)
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

int	check_map_size(t_map *map, char *filename)
{
	char	*line;
	int		fd;

	fd = open (filename, O_RDONLY);
	line = get_next_line(fd, 0);
	if (line)
		map->blocks_x = ft_strlen(line);
	map -> blocks_y = 1;
	while (1)
	{
		free (line);
		line = get_next_line(fd, 0);
		if (line == NULL)
			break ;
		map -> blocks_y += 1;
		if (map->blocks_x != ft_strlen(line))
		{
			close (fd);
			return (free(line), MLX_ERROR);
		}
		map->blocks_x = ft_strlen(line);
	}
	close (fd);
	return (0);
}

int	run_checks(int argc, t_map *map, char *filename)
{
    check_input (argc);
	if ((check_map_size (map, filename)) == MLX_ERROR)
		return (ft_printf ("Wrong map, check lines' lenght"), MLX_ERROR);
	if (map->blocks_x < 5 || map->blocks_y < 3)
		return ((ft_printf ("The map is too small")), MLX_ERROR);
	if (map->blocks_x * BLOCK_SIDE > WIDTH
		|| map->blocks_y * BLOCK_SIDE > HEIGHT)
		return ((ft_printf ("The map is too big")), MLX_ERROR);
	return (ft_printf ("Checks OK\n"), 0);
}
