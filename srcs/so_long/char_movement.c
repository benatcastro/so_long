/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/07/25 00:56:04 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/*
Recieves:
	Player info from program_data structure
	The direction that needs to move as an int
	0 = North
	1 = South
	2 = East
	3 = West
Output:
	Changes to position of the character sprite
*/
void	ft_move_character(t_character *player, int dir)
{
	if (dir == 0)
	{
		printf("move up\n");
		player->y -= IMG_RES;
	}
	if (dir == 1)
	{
		printf("move down\n");
		player->y += IMG_RES;
	}
	if (dir == 2)
	{
		printf("move left\n");
		player->x -= IMG_RES;
	}
	if (dir == 3)
	{
		printf("move right\n");
		player->x += IMG_RES;
	}
}
