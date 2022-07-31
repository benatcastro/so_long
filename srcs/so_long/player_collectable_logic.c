/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collectable_logic.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:54:35 by becastro          #+#    #+#             */
/*   Updated: 2022/07/31 23:43:15 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	ft_check_tile(t_character *player)
{
	char	**map;

	map = player->map_pos;
	if (map[player->pos_index[0]][player->pos_index[1]] == 'C')
	{
		player->collected_items++;
		printf("BARREL\n");
		//map[player->pos_index[0]][player->pos_index[1]] = "0";
		return ('0');
	}
	else if (map[player->pos_index[0]][player->pos_index[1]] == 'E')
	{
		printf("EXIT\n");
		return ('E');
	}
	return ('0');
}
