/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:10:27 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/17 09:26:42 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_mlx(t_game *so_long, t_map *map)
{
	so_long->display.mlx = mlx_init();
	if (!so_long->display.mlx)
		exit_error(so_long, "Failed to initialize mlx.");
	so_long->display.win = mlx_new_window(so_long->display.mlx, \
			map->cols * SIZE, map->rows * SIZE, "so_long");
	if (!so_long->display.win)
		exit_error(so_long, "Failed to create window.");
}

void	load_assets(t_game *so_long)
{
	so_long->sp = malloc(SPRITES * sizeof(t_sprite));
	if (!so_long->sp)
		exit_error(so_long, "Failed to allocate memory on sprites.");
	so_long->sp[W1].img = mlx_xpm_file_to_image(so_long->display.mlx, FW1, \
			&(so_long->sp[W1].width), &(so_long->sp[W1].height));
	so_long->sp[S1].img = mlx_xpm_file_to_image(so_long->display.mlx, FS1, \
			&(so_long->sp[S1].width), &(so_long->sp[S1].height));
	so_long->sp[C1].img = mlx_xpm_file_to_image(so_long->display.mlx, FC1, \
			&(so_long->sp[C1].width), &(so_long->sp[C1].height));
	so_long->sp[E1].img = mlx_xpm_file_to_image(so_long->display.mlx, FE1, \
			&(so_long->sp[E1].width), &(so_long->sp[E1].height));
	so_long->sp[P1].img = mlx_xpm_file_to_image(so_long->display.mlx, FP1, \
			&(so_long->sp[P1].width), &(so_long->sp[P1].height));
}

int	render_move(t_game *so_long)
{
	if (!check_move(so_long))
		return (0);
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(++so_long->moves, 1);
	ft_putstr_fd("\n", 1);
	if (get_tile(so_long, so_long->next) == COIN)
		so_long->coins++;
	else if (get_tile(so_long, so_long->next) == EXIT \
		&& so_long->coins == so_long->map->coins)
		quit_game(so_long);
	move_player(so_long, so_long->map);
	return (0);
}

void	render_tile(t_game *so_long, t_point p)
{
	t_sprite	sp;

	if (so_long->map->tiles[p.y][p.x] == WALL)
		sp = so_long->sp[W1];
	else if (so_long->map->tiles[p.y][p.x] == COIN)
		sp = so_long->sp[C1];
	else if (so_long->map->tiles[p.y][p.x] == EXIT)
		sp = so_long->sp[E1];
	else if (so_long->map->tiles[p.y][p.x] == SPACE)
		sp = so_long->sp[S1];
	else if (so_long->map->tiles[p.y][p.x] == PLAYER)
		sp = so_long->sp[P1];
	mlx_put_image_to_window(so_long->display.mlx, so_long->display.win, \
		sp.img, sp.width * p.x, sp.height * p.y);
}

void	render_map(t_game *so_long, t_map *map)
{
	t_uint	x;
	t_uint	y;

	y = -1;
	while (++y < map->rows)
	{
		x = -1;
		while (++x < map->cols)
			render_tile(so_long, (t_point){x, y});
	}
}
