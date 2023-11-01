/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_frees.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:47:40 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/01 13:13:01 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_assets(t_data *data)
{
	mlx_destroy_image(data->mlx, data->assets.block.img);
	mlx_destroy_image(data->mlx, data->assets.collectible.img);
	mlx_destroy_image(data->mlx, data->assets.ext.img);
	mlx_destroy_image(data->mlx, data->assets.field.img);
	mlx_destroy_image(data->mlx, data->assets.player.img);
	mlx_destroy_image(data->mlx, data->bckgrnd.img);
}

int	map_free(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->blocks_y)
		free(map->map[i++]);
	free(map->map);
	exit (0);
	return (0);
}

int	finish_him(t_data *data)
{
	destroy_assets(data);
	mlx_destroy_window(data -> mlx, data ->win);
	mlx_destroy_display(data -> mlx);
	free (data -> mlx);
	if ((data->map.map))
		map_free(&data->map);
	exit (0);
	return (0);
}
