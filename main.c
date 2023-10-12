/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:50:21 by mmakagon          #+#    #+#             */
/*   Updated: 2023/10/04 13:55:01 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define WIDTH 120
#define HEIGHT 120

#define MLX_ERROR 1

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
}				t_data;

int key_handle(int key, t_data *data)
{
	printf("Hello from key_hook! %d\n", key);
	if (key == 65307)
		mlx_destroy_window(data -> mlx, data -> win);
	return (0);
}

int	main(void)
{
	t_data		data;

	if(!(data.mlx = mlx_init()))
		return (MLX_ERROR);
	if (!(data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "do you wanna build a snowman?")))
		return (free(data.win), MLX_ERROR);

	mlx_pixel_put(data.mlx, data.win, 80, 100, 0x00ff0000);//red
	mlx_pixel_put(data.mlx, data.win, 10, 30, 0x000066ff);//blue
	mlx_pixel_put(data.mlx, data.win, 90, 10, 0x0000ff00);//green
	mlx_key_hook(data.win, key_handle, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	exit(0);
}
