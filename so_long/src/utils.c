/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 09:48:12 by wcorrea-          #+#    #+#             */
/*   Updated: 2023/05/14 12:09:54 by wcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_error(t_game *so_long, char *msg)
{
	clean_game(so_long);
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

void	check_filename(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	if (i <= 4)
		exit_error(NULL, "Invalid file name.");
	else if (!ft_strnstr((file + i - 4), ".ber", 4))
		exit_error(NULL, "Invalid file extension.");
}
