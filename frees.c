#include "so_long.h"

int kill_it_w_fire(t_data *data, t_map  *map)
{
    mlx_destroy_window(data -> mlx, data ->win);
    mlx_destroy_display(data -> mlx);
    free (data -> mlx);
    map_free(map);
    exit (0);
    return (0);
}

void    map_free(t_map *map)
{
    size_t  i;

    i = 0;
    while (i < map->blocks_y)
        free(map->map[i++]);
    exit (0);
}