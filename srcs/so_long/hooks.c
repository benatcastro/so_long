/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/25 17:53:17 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_key_hooks(int key, void *player_data)
{
	t_character	*player;

	player = player_data;
	//printf("KEY (%d)\n", key);
	if (key == ESC)
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
