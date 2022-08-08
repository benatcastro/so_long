/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 06:04:25 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 12:03:43 by becastro         ###   ########.fr       */
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
				n = rand() % SPAWN_RATE;
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
	else if (data->tick % TICKS_PER_IMG == 0)
	{
		if (data->enemies.punk.status == 3)
			data->enemies.punk.status = 0;
		data->enemies.punk.status++;
	}
}

static void	ft_move_enemie(t_program_data *data, int x, int y)
{
	char	**map;
	int		r;

	map = data->map->map_str;
	r = rand() % MOVE_RATE;
	if (r == 0 && (map[y][x - 1] == '0' || map[y][x - 1] == 'P'))
	{
		map[y][x] = '0';
		map[y][x - 1] = 'X';
	}
	if (r == 1 && (map[y][x + 1] == '0' || map[y][x + 1] == 'P'))
	{
		map[y][x] = '0';
		map[y][x + 1] = 'X';
	}
	if (r == 2 && (map[y - 1][x] == '0' || map[y - 1][x] == 'P'))
	{
		map[y][x] = '0';
		map[y - 1][x] = 'X';
	}
	if (r == 3 && (map[y + 1][x] == '0' || map[y + 1][x] == 'P'))
	{
		map[y][x] = '0';
		map[y + 1][x] = 'X';
	}
}

void	ft_enemies_move_logic(t_program_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (data->map->map_str[++y])
	{
		x = -1;
		while (data->map->map_str[y][++x])
			if (data->map->map_str[y][x] == 'X')
				ft_move_enemie(data, x, y);
	}
}
