// int	check_map_height(t_map *map, char *filename)
// {
// 	int		fd;
// 	char	*line;

// 	map->blocks_y = 0;
// 	fd = open (filename, O_RDONLY);
// 	while ((line = get_next_line(fd, 1)))
// 		map->blocks_y++;
// 	close (fd);
// 	free (line);
// 	if (map->blocks_y <= 2)
// 	{
// 		ft_printf ("The map has too few lines, please try another one");
// 		exit (MLX_ERROR);
// 		return (MLX_ERROR);
// 	}
// 	return (0);
// }

// int	check_map_width (t_map *map, char *filename)
// {
// 	int			fd;
// 	size_t		i;
// 	size_t		lenght;

// 	i = 0;
// 	lenght = 0;
// 	map->map = ft_calloc((map->blocks_y + 1), sizeof(char *));
// 	fd = open (filename, O_RDONLY);
// 	map->map[i] = get_next_line(fd, 0);
// 	lenght = ft_strlen (map->map[i]);
// 	while (++i < map->blocks_y && (map->map[i]))
// 	{
// 		map->map[i] = get_next_line(fd, 0);
// 		if (lenght != ft_strlen (map->map[i]))
// 			return (MLX_ERROR);
// 		lenght = ft_strlen (map->map[i]);
// 	}
// 	map->blocks_x = lenght;
// 	close(fd);
// 	return (0);
// }