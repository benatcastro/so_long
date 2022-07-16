/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:04:59 by bena              #+#    #+#             */
/*   Updated: 2022/05/21 11:22:15 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	get_int_null(t_args *lstargs, int arg_len, int i)
{
	arg_len = ft_strlen(lstargs->printable_arg);
	if (lstargs->first_params.nbr && !lstargs->precision_type
		&& ft_strncmp("(null)", lstargs->printable_arg, 6) == 0
		&& lstargs->first_params.sign != '-')
	{
		i = lstargs->first_params.nbr - 5;
		return (i);
	}
	if (lstargs->first_params.nbr && !lstargs->precision_type
		&& ft_strncmp("(null)", lstargs->printable_arg, 6) == 0
		&& lstargs->first_params.sign == '-')
	{
		i = lstargs->first_params.nbr - 6;
		return (i);
	}
	if ((lstargs->first_params.nbr - arg_len > arg_len
			&& (lstargs->precision_type == '.' && lstargs->type == 's')))
		i = lstargs->first_params.nbr;
	else if (ft_strncmp("(null)", lstargs->printable_arg, 6) == 0
		&& lstargs->first_params.sign != '-')
			i = lstargs->first_params.nbr + 1;
	else if (ft_strncmp("(null)", lstargs->printable_arg, 6) == 0
		&& lstargs->first_params.sign == '-')
			i = lstargs->first_params.nbr;
	return (i);
}

int	get_i_int(t_args *lstargs, int i, int arg_len, int p_size)
{
	if ((lstargs->type == 'i' || lstargs->type == 'd' )
		&& (lstargs->precision_type == '.' && lstargs->first_params.nbr > 0))
	{
		i = lstargs->first_params.nbr - p_size;
		if (lstargs->printable_arg[0] == '-'
			&& (lstargs->first_params.sign == '-' && arg_len
				> p_size))
		{
			i = arg_len - p_size + 1;
			return (i);
		}
		if (lstargs->printable_arg[0] == '-' && arg_len > p_size)
			i--;
		if (lstargs->first_params.sign == '-'
			&& arg_len
			< p_size && lstargs->printable_arg[0] != '-')
			i++;
		if (p_size > arg_len && lstargs->first_params.sign != '-'
			&& lstargs->printable_arg[0] != '-')
			i++;
		if (lstargs->first_params.sign == '-')
			i--;
	}
	return (i);
}

static int	get_i_double(t_args *lstargs, int i)
{
	int	arg_len;

	arg_len = ft_strlen(lstargs->printable_arg);
	if (lstargs->first_params.nbr > arg_len
		&& lstargs->precision_size < arg_len)
		i++;
	else if (arg_len > lstargs->precision_size
		&& lstargs->first_params.sign != '-')
		i++;
	else if (lstargs->precision_size - arg_len == 1)
		i++;
	else if (lstargs->first_params.nbr > arg_len
		&& lstargs->precision_size > arg_len)
		i += lstargs->first_params.nbr - arg_len;
	if (lstargs->first_params.nbr > arg_len
		&& lstargs->precision_size < arg_len)
		i--;
	return (i);
}

static int	ft_get_i(t_args *lstargs)
{
	int	i;
	int	j;
	int	arg_len;
	int	pre_size;

	pre_size = lstargs->precision_size;
	arg_len = ft_strlen(lstargs->printable_arg);
	j = arg_len - pre_size;
	i = lstargs->first_params.nbr - arg_len;
	if (pre_size > 0)
		i += j;
	if (lstargs->first_params.nbr > arg_len
		&& lstargs->first_params.sign != '-')
		i++;
	if (lstargs->type == 'c' && lstargs->printable_arg[0] == 0)
		i--;
	if (lstargs->first_params.nbr > 0 && pre_size > 0)
	{
		i = get_i_double(lstargs, i);
		i = get_i_int(lstargs, i, arg_len, pre_size);
	}
	i = get_int_null(lstargs, arg_len, i);
	return (i);
}

void	ft_width_print(t_args *lstargs)
{
	int	i;

	if ((lstargs->first_params.check == 1 && !lstargs->precision_type))
	{
		i = lstargs->first_params.nbr - ft_strlen(lstargs->printable_arg);
		if (lstargs->type == 's' && lstargs->first_params.sign != '-')
			i++;
	}
	else
		i = ft_get_i(lstargs);
	if (lstargs->first_params.sign != '-')
	{
		while (i-- > 0 && i)
			ft_putchar(' ', lstargs);
		ft_final_print(lstargs);
	}
	else if (lstargs->first_params.sign == '-')
	{
		ft_final_print(lstargs);
		while (i-- > 0)
			ft_putchar(' ', lstargs);
	}
}
