/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:30:11 by becastro          #+#    #+#             */
/*   Updated: 2022/07/27 14:06:40 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_win(t_program_data *data)
{
	if (data->player.collected_items == data->map->collectables)
	{
		printf("WIN WIN CHICKEN DINNER!\n");
		exit (EXIT_SUCCESS);
	}
}
