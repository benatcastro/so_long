/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_fncs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 03:51:52 by becastro          #+#    #+#             */
/*   Updated: 2022/07/26 05:07:37 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_sides(char **map, t_program_data *data)
{
	int	i;
	int	j;
	int	pos[2];

	pos[1] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		pos[0] = 0;
		while (map[i][++j])
		{
			if (j == 0)
			{
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->walls.edges_tex[2], pos[0], pos[1]);
			}
			if (j == data->map->width)
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->walls.edges_tex[3], pos[0], pos[1]);
			pos[0] += IMG_RES;
		}
		pos[1] += IMG_RES;
	}
	free(map);
}

void	ft_print_corners(char **map, t_program_data *data)
{
	int	i;
	int	j;
	int	pos[2];

	pos[1] = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		pos[0] = 0;
		while (map[i][++j])
		{
			if (j == 0 && i == 0)
				mlx_put_image_to_window(data->mlx.ptr, data->mlx.win,
					data->walls.edges_tex[4], pos[0] + 18, pos[1] + -11);
			pos[0] += IMG_RES;
		}
		pos[1] += IMG_RES;
	}
	free(map);
}
