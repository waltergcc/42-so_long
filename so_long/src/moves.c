/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:21:29 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/17 09:24:34 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_game *so_long)
{
	return (!is_same_point(so_long->curr, so_long->next) \
		&& get_tile(so_long, so_long->next) != WALL);
}

void	move_player(t_game *sl, t_map *map)
{
	static t_tile	previous = SPACE;

	map->tiles[sl->curr.y][sl->curr.x] = previous;
	if (get_tile(sl, sl->next) != COIN)
		previous = map->tiles[sl->next.y][sl->next.x];
	else
		previous = SPACE;
	map->tiles[sl->next.y][sl->next.x] = PLAYER;
	render_tile(sl, (t_point){sl->curr.x, sl->curr.y});
	render_tile(sl, (t_point){sl->next.x, sl->next.y});
	sl->curr = sl->next;
}

int	check_keypress(int key, t_game *so_long)
{
	if (key == ESC)
		quit_game(so_long);
	else if (key == W || key == UP)
		so_long->next = (t_point){so_long->curr.x, so_long->curr.y - 1};
	else if (key == S || key == DOWN)
		so_long->next = (t_point){so_long->curr.x, so_long->curr.y + 1};
	else if (key == A || key == LEFT)
		so_long->next = (t_point){so_long->curr.x - 1, so_long->curr.y};
	else if (key == D || key == RIGHT)
		so_long->next = (t_point){so_long->curr.x + 1, so_long->curr.y};
	return (key);
}
