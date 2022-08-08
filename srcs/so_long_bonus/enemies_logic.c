/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 06:04:25 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 11:23:42 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <time.h>

void	ft_spawn_enemies(t_program_data *data)
{
	int	x;
	int	y;
	int	n;

	y = -1;
	while (data->map->map_str[++y])
	{
		x = -1;
		while (data->map->map_str[y][++x])
		{
			if (data->map->map_str[y][x] == '0')
			{
				n = rand() % 4;
				if (n == 1)
					data->map->map_str[y][x] = 'X';
			}
		}

	}

}

void	ft_enemies_idle_status(t_program_data *data)
{
	if (data->tick == 0)
		data->enemies.punk.status = 0;
	else if (data->tick % 10 == 0)
	{
		if (data->enemies.punk.status == 3)
			data->enemies.punk.status = 0;
		data->enemies.punk.status++;
	}
}
