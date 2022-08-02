/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/08/02 14:30:59 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_gui(t_program_data *data)
{
	mlx_string_put(data->mlx.ptr, data->mlx.win, 10, 10, ROSE, "Movements: ");
	mlx_string_put(data->mlx.ptr, data->mlx.win, 30, 10,
		ROSE, ft_itoa(data->player.movements));
}
