/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:15:04 by becastro          #+#    #+#             */
/*   Updated: 2022/08/08 10:44:40 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "keys.h"
# include "mlx.h"
# include "get_next_line_bonus.h"

# define IMG_RES 128

# define FLAMINGO	0x00F8C4F8
# define ROSE		0x00E2252B
# define SHAMROCK	0x0003AC13
# define SEAFOAM	0x003DED97
# define ORANGE		0x00FCAE1E
# define YELLOW		0x00FFF866
# define ARCTIC		0x0082EEFD
# define CERULEAN	0x000492C2

typedef struct s_mlx_data {
	char	*path;
	void	*ptr;
	void	*win;
	char	*addr;
	int		bits_pix;
	int		len_line;
	int		endian;
}	t_data;

typedef struct s_map {
	char	**map_str;
	char	*path;
	int		fd;
	int		character;
	int		exit;
	int		enemies;
	int		collectables;
	int		valid_walls;
	int		width;
	int		height;
}	t_map;

typedef struct s_character
{
	void	*tex[5];
	char	**map_pos;
	char	direction;
	int		pos_index[2];
	int		needed_items;
	int		collected_items;
	int		movements;
	int		x;
	int		y;
}	t_character;

typedef struct s_walls
{
	void	*edges_tex[8];
	void	*walls_tex[1];
}	t_walls;

typedef struct s_floor
{
	void	*tex[2];
}	t_floor;

typedef struct s_utils
{
	void	*collect_tex[2];
	void	*exit_tex[1];
}	t_utils;
typedef struct s_program_data
{
	struct s_mlx_data	mlx;
	struct s_character	player;
	struct s_map		*map;
	struct s_walls		walls;
	struct s_floor		floor;
	struct s_utils		utils;
}	t_program_data;

/************************Game Logic******************************/

void	ft_pick_collectable(t_program_data *data);
void	ft_check_win(t_program_data *data);
/************************Mlx Functions******************************/

void	ft_load_textures(t_program_data *data);
int		ft_key_hooks(int key, void *program_data);
int		ft_mouse_hooks(int key, void *program_data);
/************************Move FNCS******************************/

t_map	ft_validate_map(char *map_path);
/************************Render FNCS******************************/

int		ft_render_frame(void *render_data);
void	ft_render_map(t_program_data *data);
void	ft_print_map(char **map);
void	ft_print_sides(t_program_data *data);
void	ft_print_corners_north(t_program_data *data);
void	ft_print_corners_south( t_program_data *data);
void	ft_print_inside_walls(t_program_data *data);
void	ft_print_inside_walls_sides(t_program_data *data);
void	ft_put_collectables(t_program_data *data);
void	ft_put_player(t_program_data *data);
/************************Move FNCS******************************/

void	ft_move_character(t_program_data *data, int dir);
char	ft_check_tile(t_program_data *data);
/************************Error management************************/
int		ft_exit_game(void *p_data);
void	ft_uitls_errors(int error_key);
void	ft_map_errors(int error_key, void *free_ptr);

#endif
