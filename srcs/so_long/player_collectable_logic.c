/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collectable_logic.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:54:35 by becastro          #+#    #+#             */
/*   Updated: 2022/07/27 15:12:37 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pick_collectable(t_program_data *data)
{
	int		x;
	int		y;
	char	**map;

	map = data->map->map_str;
	x = data->player.pos_index[1];
	y = data->player.pos_index[0];
	if (map[y][x] == 'C')
	{
		printf("C TILE\n");
		// ft_print_map(data->map->map_str);
		// data->player.collected_items++;
		// map[x][y] = '0';
		// printf("AFTER\n");
		// ft_print_map(data->map->map_str);
	}
}
