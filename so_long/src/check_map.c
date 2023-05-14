/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:00:00 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/14 12:25:14 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(t_map *map)
{
	unsigned int	i;
	unsigned int	fst_row_len;

	i = 0;
	fst_row_len = ft_strlen(map->tiles[0]);
	while (i < map->rows)
	{
		if (ft_strlen(map->tiles[i++]) != fst_row_len)
			return (0);
	}
	map->cols = fst_row_len;
	return (1);
}

void	check_map(t_game *so_long)
{
	if (!so_long->map->rows)
		exit_error(so_long, "Map is empty.");
	if (!check_format(so_long->map))
		exit_error(so_long, "Map is not a rectangle.");
}
