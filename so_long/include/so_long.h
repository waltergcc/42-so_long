/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:42:28 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/14 21:09:56 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"

# define SIZE		32
# define SPRITES	5
# define TILES		"01CEP"
# define FW1		"assets/img/1.xpm"
# define FS1		"assets/img/0.xpm"
# define FC1		"assets/img/c.xpm"
# define FE1		"assets/img/e.xpm"
# define FP1		"assets/img/p.xpm"

typedef unsigned int	t_uint;

typedef enum e_tile
{
	SPACE	= '0',
	WALL	= '1',
	COIN	= 'C',
	EXIT	= 'E',
	PLAYER	= 'P',
}			t_tile;

typedef enum e_index
{
	W1,
	S1,
	C1,
	E1,
	P1,
}		t_id;

typedef enum e_key
{
	ESC		= 65307,
	W		= 119,
	A		= 97,
	S		= 115,
	D		= 100,
	UP		= 65362,
	DOWN	= 65364,
	LEFT	= 65361,
	RIGHT	= 65363,
}			t_key;

typedef enum e_event
{
	ON_KEYPRESS	= 2,
	ON_CLOSE	= 17,
}				t_event;

typedef enum e_mask
{
	KEYPRESS_MASK	= (1L << 0),
	CLOSE_MASK		= (1L << 17)
}					t_mask;

typedef struct s_point
{
	t_uint	x;
	t_uint	y;
}			t_point;

typedef struct s_graphics
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
}			t_graphics;

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}			t_sprite;

typedef struct s_map
{
	char	**tiles;
	t_uint	cols;
	t_uint	rows;
	t_uint	coins;
	t_uint	exits;
	t_uint	players;
}			t_map;

typedef struct s_game
{
	t_map		*map;
	t_point		curr;
	t_point		next;
	t_graphics	display;
	t_sprite	*sp;
	t_uint		coins;
	t_uint		moves;
}					t_game;

t_tile	check_tile(t_game *so_long, t_point p);
int		flood_fill(t_map *map, t_point curr, char **path);
int		exit_error(t_game *so_long, char *msg);
void	check_filename(char *file);
int		is_same_point(t_point a, t_point b);

void	clean_tiles(char **tiles);
void	clean_game(t_game *so_long);
int		quit_game(t_game *so_long);

void	check_map(t_game *so_long);
void	read_map(t_game *so_long, char *file);

void	launch_mlx(t_game *so_long, t_map *map);
void	load_assets(t_game *so_long);
int		render_frame(t_game *so_long);
void	render_tile(t_game *so_long, t_point p);
void	render_map(t_game *so_long, t_map *map);

void	move_player(t_game *sl, t_map *map);
int		check_move(t_game *so_long);
int		move_control(int key, t_game *so_long);

#endif