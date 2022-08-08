/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:54:35 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 03:53:42 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	ft_check_tile(t_program_data *data)
{
	char		**map;
	t_character	*player;

	player = &data->player;
	map = player->map_pos;
	if (map[player->pos_index[0]][player->pos_index[1]] == 'C')
	{
		player->collected_items++;
		return ('0');
	}
	else if (map[player->pos_index[0]][player->pos_index[1]] == 'E')
	{
		if (player->collected_items == player->needed_items)
		{
			ft_putstr_fd("🏆WIN🏆\n", 1);
			free(data->map->map_str);
			exit(EXIT_SUCCESS);
		}
		return ('E');
	}
	return ('0');
}
