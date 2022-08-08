/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 07:59:00 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hooks(int key, void *program_data)
{
	t_program_data	*data;

	data = program_data;
	if (key == ESC)
		ft_exit_game(data);
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

int	ft_mouse_hooks(int key, void *program_data)
{
	t_program_data	*data;

	data = program_data;
	if (key == 0)
		ft_exit_game(data);
	return (key);
}
