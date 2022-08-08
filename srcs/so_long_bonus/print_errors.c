/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:38:29 by becastro          #+#    #+#             */
/*   Updated: 2022/08/03 19:36:48 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_errors(int error_key, void *free_ptr)
{
	free(free_ptr);
	if (error_key == 0)
		ft_putstr_fd("Error: map is empty ❌\n", 1);
	else if (error_key == 1)
		ft_putstr_fd("Error: map borders aren't closed correctly ❌\n", 1);
	else if (error_key == 2)
		ft_putstr_fd("Error: map walls aren't correctly placed ❌\n", 1);
	else if (error_key == 3)
		ft_putstr_fd("Error: the map doesn't have a consistent width ❌\n", 1);
	else if (error_key == 4)
		ft_putstr_fd("Error: invalid characters in map creation ❌\n", 1);
	exit (EXIT_FAILURE);
}

void	ft_uitls_errors(int error_key)
{
	if (error_key == 0)
		ft_putstr_fd("Error: map doesn't have any character ❌\n", 1);
	else if (error_key == 1)
		ft_putstr_fd("Error: map has 1 invalid exit points ❌\n", 1);
	else if (error_key == 2)
		ft_putstr_fd("Error: map doesn't have any collectable ❌\n", 1);
	exit (EXIT_FAILURE);
}
