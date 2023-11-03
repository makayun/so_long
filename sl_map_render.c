/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:48:16 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/03 13:35:58 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	victory(t_data *data)
{
	int	i;

	data->player.victory = true;
	ft_printf("VICTORY!!!\n");
	i = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->assets.vict1.img, 0, 0);
	ft_printf("You finished the game in %d steps\n", ++data->player.steps);
}

void	assets_init(t_assets *assets, t_data *data)
{
	data->canvas_x = (WIDTH - BLOCK_SIDE * data->map.blocks_x) / 2;
	data->canvas_y = (HEIGHT - BLOCK_SIDE * data->map.blocks_y) / 2;
	assets->block.img = mlx_xpm_file_to_image(data -> mlx,
			"./assets/block", &assets->block.width, &assets->block.height);
	assets->field.img = mlx_xpm_file_to_image(data -> mlx,
			"./assets/field", &assets->field.width, &assets->field.height);
	assets->collectible.img = mlx_xpm_file_to_image(data -> mlx,
			"./assets/collect", &assets->collectible.width,
			&assets->collectible.height);
	assets->ext.img = mlx_xpm_file_to_image(data -> mlx,
			"./assets/exit", &assets->ext.width, &assets->ext.height);
	assets->player.img = mlx_xpm_file_to_image(data -> mlx,
			"./assets/player", &assets->player.width, &assets->player.height);
	assets->vict1.img = mlx_xpm_file_to_image(data -> mlx,
			"./assets/vict1", &assets->vict1.width, &assets->vict1.height);
}

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
