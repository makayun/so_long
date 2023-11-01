/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:11:13 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/01 13:17:38 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_rght(t_player *player, t_map *map, t_data *data, t_assets *assets)
{
	t_position	pos;

	pos.x = data->canvas_x + player->pos.x * BLOCK_SIDE;
	pos.y = data->canvas_y + player->pos.y * BLOCK_SIDE;
	if (map->map[player->pos.y][player->pos.x + 1] == 'E'
			&& player->collectibles == 0)
		ft_printf("VICTORY");
	if (map->map[player->pos.y][player->pos.x + 1] != '1'
		&& map->map[player->pos.y][player->pos.x + 1] != 'E')
	{
		if (map->map[player->pos.y][player->pos.x + 1] == 'C')
			player->collectibles--;
		put_asset(data, assets, pos, '0');
		pos.x = data->canvas_x + (player->pos.x + 1) * BLOCK_SIDE;
		put_asset(data, assets, pos, 'P');
		map->map[player->pos.y][player->pos.x] = '0';
		map->map[player->pos.y][++player->pos.x] = 'P';
	}
}

void	move_left(t_player *player, t_map *map, t_data *data, t_assets *assets)
{
	t_position	pos;

	pos.x = data->canvas_x + player->pos.x * BLOCK_SIDE;
	pos.y = data->canvas_y + player->pos.y * BLOCK_SIDE;
	if (map->map[player->pos.y][player->pos.x - 1] == 'E'
			&& player->collectibles == 0)
		ft_printf("VICTORY");
	if (map->map[player->pos.y][player->pos.x - 1] != '1'
		&& map->map[player->pos.y][player->pos.x - 1] != 'E')
	{
		if (map->map[player->pos.y][player->pos.x - 1] == 'C')
			player->collectibles--;
		put_asset(data, assets, pos, '0');
		pos.x = data->canvas_x + (player->pos.x - 1) * BLOCK_SIDE;
		put_asset(data, assets, pos, 'P');
		map->map[player->pos.y][player->pos.x] = '0';
		map->map[player->pos.y][--player->pos.x] = 'P';
	}
}

void	move_up(t_player *player, t_map *map, t_data *data, t_assets *assets)
{
	t_position	pos;

	pos.x = data->canvas_x + player->pos.x * BLOCK_SIDE;
	pos.y = data->canvas_y + player->pos.y * BLOCK_SIDE;
	if (map->map[player->pos.y - 1][player->pos.x] == 'E'
			&& player->collectibles == 0)
		ft_printf("VICTORY");
	if (map->map[player->pos.y - 1][player->pos.x] != '1'
		&& map->map[player->pos.y - 1][player->pos.x] != 'E')
	{
		if (map->map[player->pos.y - 1][player->pos.x] == 'C')
			player->collectibles--;
		put_asset(data, assets, pos, '0');
		pos.y = data->canvas_y + (player->pos.y - 1) * BLOCK_SIDE;
		put_asset(data, assets, pos, 'P');
		map->map[player->pos.y][player->pos.x] = '0';
		map->map[--player->pos.y][player->pos.x] = 'P';
	}
}

void	move_down(t_player *player, t_map *map, t_data *data, t_assets *assets)
{
	t_position	pos;

	pos.x = data->canvas_x + player->pos.x * BLOCK_SIDE;
	pos.y = data->canvas_y + player->pos.y * BLOCK_SIDE;
	if (map->map[player->pos.y + 1][player->pos.x] == 'E'
			&& player->collectibles == 0)
		ft_printf("VICTORY");
	if (map->map[player->pos.y + 1][player->pos.x] != '1'
			&& map->map[player->pos.y + 1][player->pos.x] != 'E')
	{
		if (map->map[player->pos.y + 1][player->pos.x] == 'C')
			player->collectibles--;
		put_asset(data, assets, pos, '0');
		pos.y = data->canvas_y + (player->pos.y + 1) * BLOCK_SIDE;
		put_asset(data, assets, pos, 'P');
		map->map[player->pos.y][player->pos.x] = '0';
		map->map[++player->pos.y][player->pos.x] = 'P';
	}
}
