/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_logic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/08/01 00:40:36 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_character *player)
{
	int		x_map;
	int		y_map;
	char	**map;

	map = player->map_pos;
	x_map = player->pos_index[0];
	y_map = player->pos_index[1];
	if (map[x_map - 1][y_map] != '1')
	{
		ft_putstr_fd("move up\n", 1);
		player->y -= IMG_RES;
		player->pos_index[0]--;
		player->direction = 'N';
		map[x_map - 1][y_map] = ft_check_tile(player);
	}
}

void	ft_move_down(t_character *player)
{
	int		x_map;
	int		y_map;
	char	**map;

	map = player->map_pos;
	x_map = player->pos_index[0];
	y_map = player->pos_index[1];
	if (map[x_map + 1][y_map] != '1')
	{
		ft_putstr_fd("move down\n", 1);
		player->y += IMG_RES;
		player->pos_index[0]++;
		player->direction = 'S';
		map[x_map + 1][y_map] = ft_check_tile(player);
	}
}

void	ft_move_left(t_character *player)
{
	int		x_map;
	int		y_map;
	char	**map;

	map = player->map_pos;
	x_map = player->pos_index[0];
	y_map = player->pos_index[1];
	if (map[x_map][y_map - 1] != '1')
	{
		ft_putstr_fd("move left\n", 1);
		player->x -= IMG_RES;
		player->pos_index[1]--;
		player->direction = 'E';
		map[x_map][y_map - 1] = ft_check_tile(player);
	}
}

void	ft_move_right(t_character *player)
{
	int		x_map;
	int		y_map;
	char	**map;

	map = player->map_pos;
	x_map = player->pos_index[0];
	y_map = player->pos_index[1];
	if (map[x_map][y_map + 1] != '1')
	{
		ft_putstr_fd("move right\n", 1);
		player->x += IMG_RES;
		player->pos_index[1]++;
		player->direction = 'W';
		map[x_map][y_map + 1] = ft_check_tile(player);
	}
}

/*
Recieves:
	Player info from program_data structure
	The direction that needs to move as an int
	0 = North
	1 = South
	2 = East
	3 = West
Pos index[0] = X position on the map Matrix
Pos index[1] = Y position on the map Matrix
Output:
	Changes to position of the character sprite
*/
void	ft_move_character(t_program_data *data, int dir)
{
	if (dir == 0)
		ft_move_up(&data->player);
	else if (dir == 1)
		ft_move_down(&data->player);
	else if (dir == 2)
		ft_move_left(&data->player);
	else if (dir == 3)
		ft_move_right(&data->player);
}
