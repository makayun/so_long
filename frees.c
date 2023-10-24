/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:47:40 by mmakagon          #+#    #+#             */
/*   Updated: 2023/10/24 13:53:13 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	kill_it_w_fire(t_data *data)
{
	mlx_destroy_window(data -> mlx, data ->win);
	mlx_destroy_display(data -> mlx);
	free (data -> mlx);
	if ((data->map.map))
		map_free(&data->map);
	exit (0);
	return (0);
}

void	map_free(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->blocks_y)
		free(map->map[i++]);
	exit (0);
}
