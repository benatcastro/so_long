/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:56:49 by becastro          #+#    #+#             */
/*   Updated: 2022/07/17 16:08:13 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_parse_map(t_map map_data)
{
	get_next_line(map_data.fd);

}

int	ft_validate_map(char *map_path)
{
	t_map	map_data;

	map_data.fd = open(map_path, O_RDONLY);
	map_data.character = 0;
	map_data.collectables = 0;
	map_data.valid_walls = 0;
	map_data.map_lenghth -1;
	ft_parse_map(map_data);
}
