/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 07:28:50 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 07:59:27 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_player_status(t_program_data *data)
{
	if (data->tick == 0)
		data->player.idle_status = 0;
	if (data->tick % 10 == 0)
	{
		if (data->player.idle_status == 3)
			data->player.idle_status = 0;
		data->player.idle_status++;
	}
}

/*Chooses beetwen avaible images depending on which side is the player facing*/
static void	ft_render_player(t_program_data *data)
{
	int	idle_status;

	idle_status = data->player.idle_status;
	if (data->player.direction == 'E')
		mlx_put_image_to_window(data->mlx.ptr,
			data->mlx.win, data->player.idle_r[idle_status],
			data->player.x, data->player.y);
	else if (data->player.direction == 'N' || data->player.direction == 'S')
	{
		mlx_put_image_to_window(data->mlx.ptr,
			data->mlx.win, data->player.back[idle_status],
			data->player.x, data->player.y);
	}
	else
		mlx_put_image_to_window(data->mlx.ptr,
			data->mlx.win, data->player.idle_l[idle_status],
			data->player.x, data->player.y);
}

void	ft_player_logic_manager(t_program_data *data)
{
	ft_player_status(data);
	ft_render_player(data);
}
