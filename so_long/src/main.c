/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:44:54 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/17 09:26:31 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch_game(char *file)
{
	t_game	sl;

	ft_bzero(&sl, sizeof(t_game));
	read_map(&sl, file);
	check_map(&sl);
	launch_mlx(&sl, sl.map);
	load_assets(&sl);
	render_map(&sl, sl.map);
	mlx_hook(sl.display.win, ON_KEYPRESS, KEYPRESS_MASK, check_keypress, &sl);
	mlx_hook(sl.display.win, ON_CLOSE, CLOSE_MASK, quit_game, &sl);
	mlx_loop_hook(sl.display.mlx, render_move, &sl);
	mlx_loop(sl.display.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, "Invalid number of arguments.");
	check_filename(av[1]);
	launch_game(av[1]);
}
