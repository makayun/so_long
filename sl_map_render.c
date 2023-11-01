/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:48:16 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/01 12:55:59 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_asset(t_data *data, t_assets *assets, t_position pos, char c)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx,
			data->win, assets->block.img, pos.x, pos.y);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx,
			data->win, assets->field.img, pos.x, pos.y);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx,
			data->win, assets->player.img, pos.x, pos.y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx,
			data->win, assets->collectible.img, pos.x, pos.y);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx,
			data->win, assets->ext.img, pos.x, pos.y);
	else
		mlx_put_image_to_window(data->mlx,
			data->win, assets->block.img, pos.x, pos.y);
}

void	map_render(t_map *map, t_data *data, t_assets *assets)
{
	int			i;
	int			j;
	t_position	pos;

	i = 0;
	assets_init(assets, data);
	while (i < map->blocks_y && map->map[i])
	{
		j = 0;
		while (j < map->blocks_x)
		{
			pos.x = data->canvas_x + j * BLOCK_SIDE;
			pos.y = data->canvas_y + i * BLOCK_SIDE;
			put_asset (data, assets, pos, map->map[i][j++]);
		}
		i++;
	}
}
