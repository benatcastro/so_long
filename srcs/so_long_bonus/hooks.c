/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/27 14:24:10 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hooks(int key, void *program_data)
{
	t_program_data	*data;

	data = program_data;
	//printf("KEY (%d)\n", key);
	if (key == ESC)
		exit (0);
	if (key == W)
		ft_move_character(data, 0);
	if (key == S)
		ft_move_character(data, 1);
	if (key == A)
		ft_move_character(data, 2);
	if (key == D)
		ft_move_character(data, 3);
	return (key);
}
