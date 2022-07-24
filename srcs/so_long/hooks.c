/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/25 00:55:31 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hooks(int key, void *player_data)
{
	t_character	*player;

	player = player_data;
	//printf("KEY (%d)\n", key);
	if (key == ESC || key == CLOSE_BUTTON)
		exit (0);
	if (key == W)
		ft_move_character(player, 0);
	if (key == S)
		ft_move_character(player, 1);
	if (key == A)
		ft_move_character(player, 2);
	if (key == D)
		ft_move_character(player, 3);
	return (key);
}
