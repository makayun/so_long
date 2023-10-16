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

int	check_map(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	size_t	lenght;

	fd = open (filename, O_RDONLY);
	line = get_next_line(fd);
	lenght = ft_strlen(line);
	map -> blocks_x = 1;
	printf ("%s", line);
	free (line);
	while (1)
	{
		line = get_next_line(fd);
		map -> blocks_x += 1;
		if (strchr(line, '\n') && lenght != ft_strlen(line))
			return (1);
		printf ("%s", line);
		if (!strchr(line, '\n'))
			break ;
		lenght = ft_strlen(line);
		free (line);
	}
	map -> blocks_y = lenght - 1;
	return (0);
}
