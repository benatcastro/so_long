/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:54:35 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 05:58:54 by becastro         ###   ########.fr       */
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
			ft_exit_game(data);
		}
		return ('E');
	}
	else if (map[player->pos_index[0]][player->pos_index[1]] == 'X')
	{
		ft_putstr_fd("💀You Died💀", 1);
		ft_exit_game(data);
	}
	return ('0');
}
