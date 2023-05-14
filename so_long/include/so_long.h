/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:42:28 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/14 12:27:30 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"

typedef struct s_point
{
	unsigned int	x;
	unsigned int	y;
}					t_point;

typedef struct s_graphics
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
}					t_graphics;

typedef struct s_sprite
{
	void			*img;
	int				height;
	int				width;
}					t_sprite;

typedef struct s_map
{
	char			**tiles;
	unsigned int	cols;
	unsigned int	rows;
	unsigned int	num_postions;
	unsigned int	num_exits;
	unsigned int	num_players;
}					t_map;

typedef struct s_game
{
	t_map			*map;
	t_point			current;
	t_point			next;
	t_graphics		disp;
	t_sprite		*sp;
	unsigned int	coins;
	unsigned int	moves;
}					t_game;

int		exit_error(t_game *so_long, char *msg);
void	check_filename(char *file);

void	map_print(t_map *map); // tmp
void	clean_game(t_game *so_long);
int		quit_game(t_game *so_long);

void	read_map(t_game *so_long, char *file);
void	check_map(t_game *so_long);

#endif