/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:18:12 by mmakagon          #+#    #+#             */
/*   Updated: 2023/10/24 13:53:06 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft_plus/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 640
# define HEIGHT 480

# define BLOCK_SIDE 40

# define MLX_ERROR 1

typedef struct s_image {
	void	*img;
	char	*path;
	int		width;
	int		height;
}				t_image;

typedef struct s_map {
	char	**map;
	size_t	blocks_x;
	size_t	blocks_y;
}				t_map;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_map	map;
}				t_data;

int		kill_it_w_fire(t_data *data);
void	map_free(t_map *map);
int		key_handle(int keysym, t_data *data);
void	map_render(t_map *map, t_data *data);
int		check_input(int argc);
int		check_map_width(t_map *map, char *filename);
int		check_map_width(t_map *map, char *filename);
int		run_checks(int argc, t_map *map, char *filename);

#endif