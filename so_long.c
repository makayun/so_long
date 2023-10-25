/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:18:08 by mmakagon          #+#    #+#             */
/*   Updated: 2023/10/24 15:51:44 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_handle(int keysym, t_data *data)
{
	ft_printf("Pressed key: %d\n", keysym);
	if (keysym == XK_Escape)
		kill_it_w_fire(data);
	return (0);
}

void    map_render(t_map *map, t_data *data)
{
	size_t	i;
	size_t	j;
	t_image	block;
	t_image	field;
	t_image	collectible;
	t_image	exit;
	t_image	player;
	char	*line;

	data->canvas_x = (WIDTH - BLOCK_SIDE * map->blocks_x) / 2;
	data->canvas_y = (HEIGHT - BLOCK_SIDE * map->blocks_y) / 2;
	i = 0;
	line = (char *)ft_calloc(map->blocks_x + 1, sizeof(char));
	block.img = mlx_xpm_file_to_image(data -> mlx, "./assets/block", &block.width, &block.height);
	field.img = mlx_xpm_file_to_image(data -> mlx, "./assets/field", &field.width, &field.height);
	collectible.img = mlx_xpm_file_to_image(data -> mlx, "./assets/collect", &collectible.width, &collectible.height);
	exit.img = mlx_xpm_file_to_image(data -> mlx, "./assets/exit", &exit.width, &exit.height);
	player.img = mlx_xpm_file_to_image(data -> mlx, "./assets/player", &player.width, &player.height);
	while (i < map->blocks_y && map->map[i])
	{
		ft_strcpy(line, map->map[i]);
		j = 0;
		while (j < map->blocks_x)
		{
			if (line[j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, block.img, (data->canvas_x + (j++ * BLOCK_SIDE)), (data->canvas_y + (i * BLOCK_SIDE)));
			else if (line[j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, field.img, (data->canvas_x + (j++ * BLOCK_SIDE)), (data->canvas_y + (i * BLOCK_SIDE)));
			else if (line[j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, player.img, (data->canvas_x + (j++ * BLOCK_SIDE)), (data->canvas_y + (i * BLOCK_SIDE)));
			else if (line[j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, collectible.img, (data->canvas_x + (j++ * BLOCK_SIDE)), (data->canvas_y + (i * BLOCK_SIDE)));
			else if (line[j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, exit.img, (data->canvas_x + (j++ * BLOCK_SIDE)), (data->canvas_y + (i * BLOCK_SIDE)));
			else
				j++;
		}
		i++;
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_image		background;

	if ((run_checks(argc, &data.map, argv[1])) == MLX_ERROR)
		exit (MLX_ERROR);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (MLX_ERROR);
	if (map_init(&data.map, argv[1]) == MLX_ERROR)
	{
		free (data.mlx);
		map_free(&data.map);
	}
	if(!(data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "come on baby, light my fire")))
		return (free (data.mlx), MLX_ERROR);
	if((background.img = mlx_xpm_file_to_image(data.mlx, "./assets/background", &background.width, &background.height)))
		mlx_put_image_to_window(data.mlx, data.win, background.img, 0, 0);
	map_render(&data.map, &data);
	mlx_key_hook (data.win, key_handle, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &kill_it_w_fire, &data);
	mlx_loop(data.mlx);
	kill_it_w_fire(&data);
	return (0);
}
