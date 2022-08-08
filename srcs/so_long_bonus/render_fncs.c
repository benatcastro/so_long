/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 08:30:10 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "textures.h"
#include "limits.h"

static void	ft_render_gui(t_program_data *data)
{
	mlx_string_put(data->mlx.ptr, data->mlx.win, 10, 20, ARCTIC, "Movements: ");
	mlx_string_put(data->mlx.ptr, data->mlx.win, 80, 20, ARCTIC,
		ft_itoa(data->player.movements));
}

int	ft_render_frame(void *render_data)
{
	t_program_data	*data;

	data = render_data;
	ft_render_map(data);
	ft_populate_map(data);
	ft_player_logic_manager(data);
	ft_enemies_idle_status(data);
	ft_render_gui(data);
	if (data->tick == INT_MAX)
		data->tick = 0;
	data->tick++;
	return (data->tick);
}
