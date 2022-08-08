/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fncs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:24:40 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 04:04:36 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "textures.h"
#include "limits.h"

/*Chooses beetwen avaible images depending on which side is the player facing*/
static void	ft_render_player(t_program_data *data)
{
	if (data->player.direction == 'E')
		mlx_put_image_to_window(data->mlx.ptr,
			data->mlx.win, data->player.tex[1],
			data->player.x, data->player.y);
	else if (data->player.direction == 'N' || data->player.direction == 'S')
		mlx_put_image_to_window(data->mlx.ptr,
			data->mlx.win, data->player.tex[2],
			data->player.x, data->player.y);
	else
		mlx_put_image_to_window(data->mlx.ptr,
			data->mlx.win, data->player.tex[0],
			data->player.x, data->player.y);
}

static void	ft_render_gui(t_program_data *data)
{
	mlx_string_put(data->mlx.ptr, data->mlx.win, 10, 20, ROSE, "Movements: ");
	mlx_string_put(data->mlx.ptr, data->mlx.win, 80, 20, ROSE,
		ft_itoa(data->player.movements));
}

int	ft_render_frame(void *render_data)
{
	static int		frame;
	t_program_data	*data;

	data = render_data;
	ft_render_map(data);
	ft_put_collectables(data);
	ft_render_player(data);
	ft_render_gui(data);
	if (frame == INT_MAX)
		frame = 0;
	frame++;
	return (frame);
}
