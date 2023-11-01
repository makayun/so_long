/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:18:08 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/01 11:18:31 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_handle(int keysym, t_data *data)
{
	ft_printf("Pressed key: %d\n", keysym);
	if (keysym == XK_Escape)
		kill_it_w_fire(data);
	else if (keysym == XK_d)
		move_right(&data->player, &data->map, data, &data->assets);
	else if (keysym == XK_a)
		move_left(&data->player, &data->map, data, &data->assets);
	else if (keysym == XK_w)
		move_up(&data->player, &data->map, data, &data->assets);
	else if (keysym == XK_s)
		move_down(&data->player, &data->map, data, &data->assets);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;
	
	if ((run_checks(argc, &data.map, argv[1])) == MLX_ERROR)
		exit (MLX_ERROR);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (MLX_ERROR);
	if (map_init(&data, argv[1]) == MLX_ERROR)
	{
		free (data.mlx);
		map_free(&data.map);
	}
	if(!(data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "come on baby, light my fire")))
		return (free (data.mlx), MLX_ERROR);
	if((data.background.img = mlx_xpm_file_to_image(data.mlx, "./assets/background", &data.background.width, &data.background.height)))
		mlx_put_image_to_window(data.mlx, data.win, data.background.img, 0, 0);
	map_render(&data.map, &data, &data.assets);
	mlx_key_hook (data.win, key_handle, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &kill_it_w_fire, &data);
	mlx_loop(data.mlx);
	kill_it_w_fire(&data);
	return (0);
}
