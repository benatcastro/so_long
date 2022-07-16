/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:46:23 by bena              #+#    #+#             */
/*   Updated: 2022/05/21 11:00:07 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_print_hexa_prefix(t_args *lstargs)
{
	if ((lstargs->type == 'x' && lstargs->prefix == '#')
		&& lstargs->printable_arg[0] != '0')
	{
		ft_putstr("0x", lstargs);
		lstargs->precision_size -= 2;
	}
	if ((lstargs->type == 'X' && lstargs->prefix == '#')
		&& lstargs->printable_arg[0] != '0')
	{
		ft_putstr("0X", lstargs);
		lstargs->precision_size -= 2;
	}
}

void	ft_print_prefix(t_args *lstargs)
{
	if (lstargs->prefix)
	{
		ft_print_hexa_prefix(lstargs);
		if ((lstargs->type == 'd' || lstargs->type == 'i')
			&& lstargs->prefix == ' '
			&& lstargs->printable_arg[0] != '-')
		{
			ft_putchar(' ', lstargs);
			lstargs->precision_size--;
		}
		else if ((lstargs->type == 'd' || lstargs->type == 'i')
			&& lstargs->prefix == '+')
		{
			if (lstargs->printable_arg[0] == '-')
				return ;
			else
			{
				ft_putchar('+', lstargs);
				lstargs->precision_size--;
			}
		}
	}
}
