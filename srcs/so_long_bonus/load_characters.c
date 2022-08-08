/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_characters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 05:36:29 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 07:58:06 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_load_player_idle(t_program_data *data)
{
	int			res;

	res = IMG_RES;
	data->player.idle_l[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/idle/idle_0_l.xpm", &res, &res);
	data->player.idle_l[1] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/idle/idle_1_l.xpm", &res, &res);
	data->player.idle_l[2] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/idle/idle_2_l.xpm", &res, &res);
	data->player.idle_l[3] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/idle/idle_3_l.xpm", &res, &res);
	data->player.idle_r[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/idle/idle_0_r.xpm", &res, &res);
	data->player.idle_r[1] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/idle/idle_1_r.xpm", &res, &res);
	data->player.idle_r[2] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/idle/idle_2_r.xpm", &res, &res);
	data->player.idle_r[3] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/idle/idle_3_r.xpm", &res, &res);
}

void	ft_load_player(t_program_data *data)
{
	int			res;

	res = IMG_RES;
	data->player.back[0] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/back/biker_back_0.xpm", &res, &res);
	data->player.back[1] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/back/biker_back_1.xpm", &res, &res);
	data->player.back[2] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/back/biker_back_2.xpm", &res, &res);
	data->player.back[3] = mlx_xpm_file_to_image(data->mlx.ptr,
			"textures/biker/back/biker_back_3.xpm", &res, &res);
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
