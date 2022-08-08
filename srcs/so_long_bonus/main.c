/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 20:48:01 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 04:11:58 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static size_t	ft_read_len(char *path)
{
	int		rd;
	int		fd;
	size_t	i;
	char	*buffer;

	i = 0;
	rd = 1;
	buffer = malloc(1);
	fd = open (path, O_RDONLY);
	while (rd != 0)
	{
		rd = read(fd, buffer, 1);
		i++;
	}
	free(buffer);
	close(fd);
	return (i);
}

static void	ft_init_window(int width, int height, t_map *map_data)
{
	t_program_data	data;

	data.player.collected_items = 0;
	data.player.movements = 0;
	data.map = map_data;
	data.player.map_pos = map_data->map_str;
	data.player.needed_items = map_data->collectables;
	data.mlx.ptr = mlx_init();
	data.mlx.win = mlx_new_window(data.mlx.ptr, width, height, "so_long_bonus");
	ft_load_textures(&data);
	ft_render_map(&data);
	ft_put_player(&data);
	mlx_key_hook(data.mlx.win, ft_key_hooks, &data);
	mlx_hook(data.mlx.win, 17, 0, ft_exit_game, &data);
	mlx_loop_hook(data.mlx.ptr, ft_render_frame, &data);
	mlx_loop(data.mlx.ptr);
}

int	ft_exit_game(void *p_data)
{
	t_program_data	*data;

	data = p_data;
	free(data->map->map_str);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_map	map;
	size_t	map_len;
	char	*map_str;
	int		fd;

	if (argc != 2)
		return (0);
	map.path = argv[1];
	map = ft_validate_map(map.path);
	map_len = ft_read_len(map.path);
	map_str = malloc(map_len);
	fd = open(map.path, O_RDONLY);
	read (fd, map_str, (int)map_len);
	close(fd);
	map.map_str = ft_split(map_str, '\n');
	ft_init_window((map.width + 1) * IMG_RES, (map.height + 1) * IMG_RES, &map);
}
