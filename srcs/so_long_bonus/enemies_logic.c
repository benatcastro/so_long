/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 06:04:25 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 06:41:59 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <time.h>


void	ft_render_enemies(t_program_data *data, int x, int y)
{
//	int	r;

	//r = rand() % 2;
//	if (r == 1)
		mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
			data->enemies.punk.idle_tex[data->enemies.punk.status], x, y);
	//else if (r == 0)
	//	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
	//		data->player.tex[0], x, y);
}

void	ft_enemies_idle_status(t_program_data *data)
{
	if (data->tick == 0)
	{
		data->enemies.punk.status = 0;
	}
	if (data->tick % 10 == 0)
	{
		if (data->enemies.punk.status == 3)
			data->enemies.punk.status = 0;
		data->enemies.punk.status++;
	}
}
