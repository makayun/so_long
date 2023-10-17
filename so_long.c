/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:18:08 by mmakagon          #+#    #+#             */
/*   Updated: 2023/10/16 15:43:40 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int kill_it_w_fire(t_data *data)
{
    mlx_destroy_window(data -> mlx, data ->win);
    mlx_destroy_display(data -> mlx);
    free (data -> mlx);
    exit (0);
    return (0);
}

int key_handle(int keysym, t_data *data)
{
    ft_printf("Pressed key: %d\n", keysym);
    if (keysym == XK_Escape)
        kill_it_w_fire(data);
    return (0);
}

void map_read(t_map *map) // complete me!!!
{
    map -> blocks_x = 10;
    map -> blocks_y = 1;
}

void    map_render(t_map *map, t_data *data)
{
    size_t  canvas_x;
    size_t  canvas_y;
    size_t  i;
    t_image block;

    canvas_x = (WIDTH - BLOCK_SIDE * map -> blocks_x) / 2;
    canvas_y = (HEIGHT - BLOCK_SIDE * map -> blocks_y) / 2;
    i = 0;
    if ((block.img = mlx_xpm_file_to_image(data -> mlx, "./assets/block", &block.width, &block.height)))
    {
        while (i < map -> blocks_x)
            mlx_put_image_to_window(data -> mlx, data -> win, block.img, (canvas_x + (i++ * BLOCK_SIDE)), canvas_y);
    }
}

int main(int argc, char **argv)
{
    t_data  data;
    t_image background;
    t_map   map;

    run_checks(argc, &map, argv[1]);
    if(!(data.mlx = mlx_init()))
        return (MLX_ERROR);
    if(!(data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "come on baby, light my fire")))
        return (free (data.mlx), MLX_ERROR);
    if((background.img = mlx_xpm_file_to_image(data.mlx, "./assets/background", &background.width, &background.height)))
        mlx_put_image_to_window(data.mlx, data.win, background.img, 0, 0);
    map_read(&map); // complete later
    map_render(&map, &data);
    mlx_key_hook (data.win, key_handle, &data);
    mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &kill_it_w_fire, &data);
    mlx_loop(data.mlx);
    kill_it_w_fire(&data);
    return (0);        
}
