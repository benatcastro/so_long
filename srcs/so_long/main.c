/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:48:01 by becastro          #+#    #+#             */
/*   Updated: 2022/07/19 19:40:03 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "textures.h"

int	main(int argc, char **argv)
{
	t_data	mlx_data;
	t_map	map_data;
	void	*img;
	int		test1 = 128;
	int		test2 = 128;

	if (argc != 2)
		return (0);
	map_data = ft_validate_map(argv[1]);
	mlx_data.win_id = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.win_id, (IMAGE_RES * map_data.width),
			(IMAGE_RES * map_data.height), "so_long");

	img = mlx_xpm_file_to_image(mlx_data.win_id, "julen_test.xpm", &test1, &test2);
	printf("IMG (%p)", img);
	//mlx_put_image_to_window(mlx_data.win_id, mlx_data.win, img, 100, 100);
	mlx_key_hook(mlx_data.win, ft_key_hooks, NULL);
	mlx_hook(mlx_data.win, 17, 1L << 17, ft_key_hooks, NULL);
	mlx_loop(mlx_data.win_id);
}

