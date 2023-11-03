/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakagon <mmakagon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:18:12 by mmakagon          #+#    #+#             */
/*   Updated: 2023/11/03 12:32:19 by mmakagon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdbool.h>
# include <math.h>
# include "./mlx/mlx.h"
# include "./libft_plus/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 1920
# define HEIGHT 1080

# define BLOCK_SIDE 40

# define MLX_ERROR 1

typedef struct s_image {
	void	*img;
	int		width;
	int		height;
}				t_image;

typedef struct s_map {
	char	**map;
	int		blocks_x;
	int		blocks_y;
}				t_map;

typedef struct s_assets {
	t_image	block;
	t_image	field;
	t_image	collectible;
	t_image	ext;
	t_image	player;
	t_image	vict1;
}				t_assets;

typedef struct s_position {
	int		x;
	int		y;
}				t_position;

typedef struct s_player {
	t_position	pos;
	int			collectibles;
	int			steps;
	bool		victory;
}				t_player;

typedef struct s_data {
	void		*mlx;
	void		*win;
	t_map		map;
	t_assets	assets;
	t_player	player;
	t_image		bckgrnd;
	int			canvas_x;
	int			canvas_y;
}				t_data;

// checks
int		run_checks(int argc, t_data *data, char *filename);
int		check_input(int argc, char *filename);
int		check_map_contents(char *filename, t_map *map);
int		count_columns_and_rows(char *whole_map, t_map *map);

// map init
int		map_init(t_data *data, char *filename);
int		map_read(t_map *map, char *filename);
int		check_walls(t_map *map);

// check if collectibles and exit are accesible
int		is_there_the_way(t_data *data);
bool	find_the_way(int x, int y, bool **visited, t_data *data);
bool	**visited_allocate(int x, int y, bool **visited);
void	visited_free(bool **visited, int rows);

// assets init
void	assets_init(t_assets *assets, t_data *data);

// game init
int		lets_get_it_started(t_data *data);

// map render
void	map_render(t_map *map, t_data *data, t_assets *assets);
void	put_asset(t_data *data, t_assets *assets, t_position pos, char c);

// keys and movement
int		key_handle(int keysym, t_data *data);
void	move_rght(t_player *player, t_map *map, t_data *data, t_assets *assets);
void	move_left(t_player *player, t_map *map, t_data *data, t_assets *assets);
void	move_up(t_player *player, t_map *map, t_data *data, t_assets *assets);
void	move_down(t_player *player, t_map *map, t_data *data, t_assets *assets);

// victory
void	victory(t_data *data);

// finish him!
int		finish_him(t_data *data);
int		map_free(t_map *map);
void	assets_destroy(t_data *data);

#endif