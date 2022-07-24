/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:48:01 by becastro          #+#    #+#             */
/*   Updated: 2022/07/24 23:21:18 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "textures.h"

static void	ft_init_window(int width, int height)
{
	t_program_data	data;

	//void	*img;
	// int		i;

	// frame = ft_calloc(1, sizeof(t_frame));
	data.mlx.ptr = mlx_init();
	ft_load_textures(&data);
	data.mlx.win = mlx_new_window(data.mlx.ptr, width, height, "so_long");
	// data.player.tex[2] = mlx_xpm_file_to_image(data.mlx.ptr, "textures/blue_test.xpm", &i, &i);
	// mlx_put_image_to_window(data.mlx.ptr, data.mlx.win, data.player.tex[0], 0, 0);
	mlx_key_hook(data.mlx.win, ft_key_hooks, NULL);
	mlx_hook(data.mlx.win, 17, 1L << 17, ft_key_hooks, NULL);
	mlx_loop_hook(data.mlx.ptr, ft_render_frame, &data);
	mlx_loop(data.mlx.ptr);
}

int	main(int argc, char **argv)
{
	t_map	map_data;

	if (argc != 2)
		return (0);
	map_data = ft_validate_map(argv[1]);
	ft_init_window(map_data.width * IMG_RES, map_data.height * IMG_RES);
}
