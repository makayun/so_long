#include "so_long.h"

void	visited_free(bool **visited)
{
	int	i;

	i = 0;
	if (visited != NULL)
	{
		while (visited[i] != NULL)
			free (visited[i++]);
		free (visited);
	}
}

bool	**visited_allocate(int x, int y)
{
	bool **visited;
	int i;

	i = 0;
	visited = (bool **)malloc(y * sizeof(bool *));
	if (visited == NULL)
		return (NULL);
	while (i < y)
	{
		visited[i] = (bool *)malloc(x * sizeof(bool));
		if (visited[i] == NULL)
			return (visited_free(visited), NULL);
		i++;
	}
	return (visited);
}

bool	find_the_way(int x, int y, bool **visited, t_data *data)
{
	if (y <= 0 || y >= data->map.blocks_y || x <= 0 || x >= data->map.blocks_x || visited[y][x] || data->map.map[y][x] == '1')
		return (false);
	if (data->map.map[y][x] != '1')
	{
		if (data->map.map[y][x] == 'C' || data->map.map[y][x] == 'E')
			data->player.collectibles--;
		visited[y][x] = true;
		if (data->player.collectibles == 0)
			return (true);
	}
	return (find_the_way(x, y + 1, visited, data) || find_the_way(x, y - 1, visited, data) || find_the_way(x + 1, y, visited, data) || find_the_way(x - 1, y, visited, data));
}

void	is_there_the_way(t_data *data)
{
	bool        **visited;
	int         collectibles;

	visited = visited_allocate(data->map.blocks_x, data->map.blocks_y);
	if (visited == NULL)
		return ;
	collectibles = data->player.collectibles;
	data->player.collectibles++;
	if (find_the_way(data->player.pos.x, data->player.pos.y, visited, data) == true)
		ft_printf ("There is the way!\n");
	else
		ft_printf ("You shall not pass!\n");
	data->player.collectibles = collectibles;
}