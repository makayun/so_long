/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_find_the_way.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:45:29 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/01 11:53:24 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	visited_free(bool **visited, int rows)
{
	int	i;

	i = 0;
	if (visited != NULL)
	{
		while (i < rows && visited[i] != NULL)
			free (visited[i++]);
		free (visited);
	}
}

bool	**visited_allocate(int x, int y, bool **visited)
{
	int	i;

	i = 0;
	visited = (bool **)malloc(y * sizeof(bool *));
	if (visited == NULL)
		return (NULL);
	while (i < y)
	{
		visited[i] = (bool *)ft_calloc(x, sizeof(bool));
		if (visited[i] == NULL)
			return (visited_free(visited, y), NULL);
		i++;
	}
	return (visited);
}

bool	find_the_way(int x, int y, bool **visited, t_data *data)
{
	if (y <= 0 || y >= data->map.blocks_y
		|| x <= 0 || x >= data->map.blocks_x
		|| visited[y][x] || data->map.map[y][x] == '1')
		return (false);
	if (data->map.map[y][x] != '1')
	{
		if (data->map.map[y][x] == 'C' || data->map.map[y][x] == 'E')
			data->player.collectibles--;
		visited[y][x] = true;
	}
	if (data->player.collectibles == 0)
		return (true);
	else
		return (find_the_way(x, y + 1, visited, data)
			|| find_the_way(x, y - 1, visited, data)
			|| find_the_way(x + 1, y, visited, data)
			|| find_the_way(x - 1, y, visited, data));
}

void	is_there_the_way(t_data *data)
{
	bool	**visited;
	int		collectibles;

	visited = NULL;
	visited = visited_allocate(data->map.blocks_x, data->map.blocks_y, visited);
	if (visited == NULL)
		return ;
	collectibles = data->player.collectibles;
	data->player.collectibles++;
	if (find_the_way(data->player.pos.x,
			data->player.pos.y, visited, data) == true)
		ft_printf ("There is the way!\n");
	else
		ft_printf ("You shall not pass!\n");
	visited_free(visited, data->map.blocks_y);
	data->player.collectibles = collectibles;
}
