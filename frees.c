#include "so_long.h"

void kill_it_w_fire(t_data *data, t_map  *map)
{
    size_t i;

    i = 0;
    mlx_destroy_window(data -> mlx, data ->win);
    mlx_destroy_display(data -> mlx);
    free (data -> mlx);
    while (i < map->blocks_y)
        free(map->map[i++]);
    exit (0);
}

void    map_free(t_map *map)
{
    size_t  i;

    i = 0;
    while (i < map->blocks_y)
        free(map->map[i++]);
    exit (0);
}