/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 05:36:29 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 07:11:21 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_load_player(t_program_data *data)
{
	int			res;

	res = IMG_RES;
	data->player.tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/biker_back.xpm", &res, &res);
	data->player.tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/biker_back.xpm", &res, &res);
}

void	ft_load_punk(t_program_data *data)
{
	int			res;

	res = IMG_RES;
	data->enemies.punk.idle_tex[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/punk/idle_left/punk_idle_0_l.xpm", &res, &res);
	data->enemies.punk.idle_tex[1] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/punk/idle_left/punk_idle_1_l.xpm", &res, &res);
	data->enemies.punk.idle_tex[2] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/punk/idle_left/punk_idle_2_l.xpm", &res, &res);
	data->enemies.punk.idle_tex[3] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/punk/idle_left/punk_idle_3_l.xpm", &res, &res);
}
