/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:48:01 by becastro          #+#    #+#             */
/*   Updated: 2022/07/20 05:06:08 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "textures.h"

static void	ft_init_window(int width, int height)
{
	t_data	mlx_data;
	t_frame	*frame;
	//void	*img;
	//int		i;

	frame = ft_calloc(1, sizeof(t_frame));
	mlx_data.ptr = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.ptr, width, height, "so_long");
	frame->mlx_ptr = mlx_data.ptr;
	frame->mlx_win = mlx_data.win;
	ft_load_textures(&mlx_data, frame);
	//img = mlx_xpm_file_to_image(mlx_data.ptr, "textures/blue_test.xpm", &i, &i);
	//printf("IMG %p", img);
	mlx_key_hook(mlx_data.win, ft_key_hooks, NULL);
	mlx_hook(mlx_data.win, 17, 1L << 17, ft_key_hooks, NULL);
	mlx_loop_hook(mlx_data.ptr, ft_render_frame, &frame);
	mlx_loop(mlx_data.ptr);
}

int	main(int argc, char **argv)
{
	t_map	map_data;

	if (argc != 2)
		return (0);
	map_data = ft_validate_map(argv[1]);
	ft_init_window(map_data.width * IMG_RES, map_data.height * IMG_RES);
}
