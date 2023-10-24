/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:18:08 by mmakagon          #+#    #+#             */
/*   Updated: 2023/10/24 15:13:28 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_read(t_map *map, char *filename)
{
	int     fd;
	size_t  i;

	map->map = (char **)ft_calloc((map->blocks_y) + 1, sizeof(char *));
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < map->blocks_y)
		map->map[i++] = get_next_line(fd, 0);
	close (fd);
	return (0);
}

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
	char	line[map->blocks_x];

	data->canvas_x = (WIDTH - BLOCK_SIDE * map->blocks_x) / 2;
	data->canvas_y = (HEIGHT - BLOCK_SIDE * map->blocks_y) / 2;
	i = 0;
	block.img = mlx_xpm_file_to_image(data -> mlx, "./assets/block", &block.width, &block.height);
	while (i < map->blocks_y)
	{
		ft_strcpy(line, map->map[i]);
		j = 0;
		while (j < map->blocks_x)
		{
			if (line[j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, block.img, (data->canvas_x + (j++ * BLOCK_SIDE)), (data->canvas_y + (i * BLOCK_SIDE)));
			else
				j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_image		background;

	if ((run_checks(argc, &data.map, argv[1])) == MLX_ERROR)
		exit (MLX_ERROR);
	if(!(data.mlx = mlx_init()))
		return (MLX_ERROR);
	if(!(data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "come on baby, light my fire")))
		return (free (data.mlx), MLX_ERROR);
	if((background.img = mlx_xpm_file_to_image(data.mlx, "./assets/background", &background.width, &background.height)))
		mlx_put_image_to_window(data.mlx, data.win, background.img, 0, 0);
	map_read(&data.map, argv[1]);
	if (check_map_content(&data.map) != MLX_ERROR)
		map_render(&data.map, &data);
	mlx_key_hook (data.win, key_handle, &data);
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &kill_it_w_fire, &data);
	mlx_loop(data.mlx);
	kill_it_w_fire(&data);
	return (0);
}
