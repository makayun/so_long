#include "./libft_plus/libft.h"

typedef struct s_map {
    char    **map;
    size_t  blocks_x;
    size_t  blocks_y;
}               t_map;

int    check_map(t_map *map, char *filename)
{
    int fd;
    char *line;
    size_t  lenght;

    fd = open (filename, O_RDONLY);
    line = get_next_line(fd);
    lenght = ft_strlen(line);
    map -> blocks_x = 1;
    printf ("%s", line);
    free (line);
    while (1)
    {
        line = get_next_line(fd);
        map -> blocks_x += 1;
        if (strchr(line, '\n') && lenght != ft_strlen(line))
            return (1);
        printf ("%s", line);
        if (!strchr(line, '\n'))
            break ;
        lenght = ft_strlen(line);
        free (line);
    }
    map -> blocks_y = lenght - 1;
    return (0);
}

int main(int argc, char **argv)
{
    t_map   map;
    if (check_map (&map, argv[1]) == 1)
        printf ("wrong");
    else
        printf ("\n%zu %zu", map.blocks_y, map.blocks_x);
    return (0);
}