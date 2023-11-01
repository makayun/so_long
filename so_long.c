/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:18:08 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/01 13:19:42 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handle(int keysym, t_data *data)
{
	ft_printf("Pressed key: %d\n", keysym);
	if (keysym == XK_Escape)
		finish_him(data);
	else if (keysym == XK_d || keysym == XK_Right)
		move_rght(&data->player, &data->map, data, &data->assets);
	else if (keysym == XK_a || keysym == XK_Left)
		move_left(&data->player, &data->map, data, &data->assets);
	else if (keysym == XK_w || keysym == XK_Up)
		move_up(&data->player, &data->map, data, &data->assets);
	else if (keysym == XK_s || keysym == XK_Down)
		move_down(&data->player, &data->map, data, &data->assets);
	return (0);
}

int	lets_start_the_party(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit (MLX_ERROR);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT,
			"come on baby, light my fire");
	if (!data->win)
	{
		free (data->mlx);
		return (map_free(&data->map), MLX_ERROR);
	}
	data->bckgrnd.img = mlx_xpm_file_to_image(data->mlx,
			"./assets/background", &data->bckgrnd.width, &data->bckgrnd.height);
	if (data->bckgrnd.img != NULL)
		mlx_put_image_to_window(data->mlx, data->win, data->bckgrnd.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		data;

	if ((run_checks(argc, &data, argv[1])) == MLX_ERROR)
		exit (MLX_ERROR);
	lets_start_the_party(&data);
	map_render(&data.map, &data, &data.assets);
	mlx_key_hook (data.win, key_handle, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &finish_him, &data);
	mlx_loop(data.mlx);
	finish_him(&data);
	return (0);
}
