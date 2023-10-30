/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_assets_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:42:21 by mmakagon          #+#    #+#             */
/*   Updated: 2023/10/30 13:01:55 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void assets_init(t_assets *assets, t_data *data)
{
    data->canvas_x = (WIDTH - BLOCK_SIDE * data->map.blocks_x) / 2;
	data->canvas_y = (HEIGHT - BLOCK_SIDE * data->map.blocks_y) / 2;
	assets->block.img = mlx_xpm_file_to_image(data -> mlx, "./assets/block", &assets->block.width, &assets->block.height);
	assets->field.img = mlx_xpm_file_to_image(data -> mlx, "./assets/field", &assets->field.width, &assets->field.height);
	assets->collectible.img = mlx_xpm_file_to_image(data -> mlx, "./assets/collect", &assets->collectible.width, &assets->collectible.height);
	assets->ext.img = mlx_xpm_file_to_image(data -> mlx, "./assets/exit", &assets->ext.width, &assets->ext.height);
	assets->player.img = mlx_xpm_file_to_image(data -> mlx, "./assets/player", &assets->player.width, &assets->player.height);
}