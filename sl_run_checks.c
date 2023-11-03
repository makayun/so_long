/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_run_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:23:55 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/03 13:37:58 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_input(int argc, char *filename)
{
	if (argc <= 1)
	{
		ft_printf("Error\nPlease, choose any map and try again\n");
		exit (MLX_ERROR);
		return (MLX_ERROR);
	}
	else if (argc > 2)
	{
		ft_printf("Error\nToo many arguments, try again!\n");
		exit (MLX_ERROR);
		return (MLX_ERROR);
	}
	else if (!ft_strnstr(filename, ".ber", ft_strlen(filename))
		|| !ft_strnstr(filename, "./", 2))
	{
		ft_printf("Error\nWrong map name!\n");
		exit (MLX_ERROR);
		return (MLX_ERROR);
	}
	else
		return (0);
}

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
			i++;
		if ((i - map->blocks_y) / map->blocks_x != map->blocks_y + 1)
			return (-3);
		map->blocks_y++;
		i++;
	}
	return (0);
}

int	count_p_and_e(char *whole_map)
{
	int	p;
	int	e;
	int	i;

	p = 0;
	e = 0;
	i = 0;
	while (whole_map[i])
	{
		if (whole_map[i] == 'P')
			p++;
		else if (whole_map[i] == 'E')
			e++;
		if (p > 1 || e > 1)
			return (MLX_ERROR);
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
	else if (count_p_and_e(whole_map) == MLX_ERROR)
		check = -5;
	else
		check = count_columns_and_rows(whole_map, map);
	free (whole_map);
	return (check);
}

int	run_checks(int argc, t_data *data, char *filename)
{
	int	check;

	check_input (argc, filename);
	check = check_map_contents(filename, &data->map);
	if (check == -1)
		return (ft_printf("Error\nThe map is too big!\n"), MLX_ERROR);
	else if (check == -2)
		return (ft_printf("Error\nSomething is missing in the map!\n"),
			MLX_ERROR);
	else if (check == -3)
		return (ft_printf("Error\nInvalid map, check lines' lenght!\n"),
			MLX_ERROR);
	else if (check == -4)
		return (ft_printf("Error\nThe map is empty or invalid!\n"),
			MLX_ERROR);
	else if (check == -5)
		return (ft_printf("Error\nToo many players or exits on the map!\n"),
			MLX_ERROR);
	if (map_init(data, filename) == MLX_ERROR)
		return (MLX_ERROR);
	return (0);
}
