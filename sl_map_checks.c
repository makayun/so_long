/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:23:55 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/02 15:48:43 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_columns_and_rows(char *whole_map, t_map *map)
{
	int	i;

	i = 0;
	while (whole_map[i] != '\n' && whole_map[i] != '\0')
		++i;
	if (i == 0)
		return (-4);
	map->blocks_x = i;
	map->blocks_y = 1;
	i++;
	while (whole_map[i] != '\0')
	{
		while (whole_map[i] != '\n' && whole_map[i] != '\0')
			++i;
		if ((i - map->blocks_y) / map->blocks_x != map->blocks_y + 1)
			return (-3);
		map->blocks_y++;
		i++;
	}
	return (0);
}

int	check_map_contents(char *filename, t_map *map)
{
	int		fd;
	int		check;
	int		max_size;
	char	*whole_map;

	max_size = (WIDTH / BLOCK_SIDE) * (HEIGHT / BLOCK_SIDE);
	whole_map = (char *)ft_calloc((max_size + 1), sizeof(char));
	fd = open (filename, O_RDONLY);
	check = read (fd, whole_map, max_size);
	close (fd);
	if (check >= max_size -1)
		check = -1;
	else if (!ft_strchr(whole_map, '1') || !ft_strchr(whole_map, 'P')
		|| !ft_strchr(whole_map, 'C') || !ft_strchr(whole_map, 'E'))
		check = -2;
	else
		check = count_columns_and_rows(whole_map, map);
	free (whole_map);
	return (check);
}

int	run_checks(int argc, t_data *data, char *filename)
{
	int	check;

	check_input (argc);
	check = check_map_contents(filename, &data->map);
	if (check == -1)
		return (ft_printf("Error\nThe map is too big!\n"), MLX_ERROR);
	else if (check == -2)
		return (ft_printf("Error\nSomething is missing in the map!\n"), MLX_ERROR);
	else if (check == -3)
		return (ft_printf("Error\nInvalid map, check lines' lenght\n"), MLX_ERROR);
	else if (check == -4)
		return (ft_printf("Error\nThe map starts from a newline symbol\n"), MLX_ERROR);
	if (map_init(data, filename) == MLX_ERROR)
		return (MLX_ERROR);
	return (ft_printf ("Checks OK\n"), 0);
}
