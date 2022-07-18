/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:38:29 by becastro          #+#    #+#             */
/*   Updated: 2022/07/18 04:08:50 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_errors(int error_key)
{
	if (error_key == 0)
		perror("Error: map is empty\n");
	else if (error_key == 1)
		perror("Error: map borders aren't closed correctly\n");
	else if (error_key == 2)
		perror("Error: map walls aren't correctly placed\n");
	else if (error_key == 3)
		perror("Error: the map doesn't have a consistent width\n");
	else if (error_key == 4)
		perror("Error: invalid characters in map creation\n");
	exit (EXIT_FAILURE);
}
