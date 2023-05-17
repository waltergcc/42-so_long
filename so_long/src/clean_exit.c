/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:28:49 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/17 11:43:42 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_tiles(char **tiles)
{
	size_t	i;

	i = 0;
	if (!tiles)
		return ;
	while (tiles[i])
		free (tiles[i++]);
	free (tiles);
}

void	clean_map(t_map *map)
{
	if (!map)
		return ;
	clean_tiles(map->tiles);
	free (map);
}


void	clean_sprites(t_game *so_long)
{
	int	i;

	i = -1;
	while (++i < SPRITES)
		mlx_destroy_image(so_long->display.mlx, so_long->sp[i].img);
	free (so_long->sp);
}

void	clean_game(t_game *so_long)
{
	if (!so_long)
		return ;
	if (so_long->map)
		clean_map(so_long->map);
	if (so_long->sp)
		clean_sprites(so_long);
	if (so_long->display.win)
		mlx_destroy_window(so_long->display.mlx, so_long->display.win);
	if (so_long->display.mlx)
		mlx_destroy_display(so_long->display.mlx);
	free(so_long->display.mlx);
}

int	quit_game(t_game *so_long)
{
	clean_game(so_long);
	exit(EXIT_SUCCESS);
}
