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
        exit (0);
        return (0);
    }
    else if (argc > 2)
    {
        ft_printf("Too much arguments, try again!");
        exit (0);
        return (0);
    }
    else
        return (1);
}

int	check_map_width(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	size_t	lenght;

	fd = open (filename, O_RDONLY);
	line = get_next_line(fd);
	lenght = ft_strlen(line);
	map -> blocks_x = 1;
	ft_printf ("%s", line);
	free (line);
	while (1)
	{
		line = get_next_line(fd);
		map -> blocks_x += 1;
		if (strchr(line, '\n') && lenght != ft_strlen(line))
			return (1);
		ft_printf ("%s", line);
		if (!strchr(line, '\n'))
			break ;
		lenght = ft_strlen(line);
		free (line);
	}
	map -> blocks_y = lenght - 1;
	return (0);
}

void	run_checks(int argc, t_map *map, char *filename)
{
	check_input (argc);
	if (check_map_width (map, filename) == MLX_ERROR)
	{
		ft_printf ("Invalid map, try again!");
		exit (0);
	}
}