/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 22:47:59 by bena              #+#    #+#             */
/*   Updated: 2022/05/21 11:42:53 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_base(unsigned long long nbr, int base)
{
	t_nbr_data	nbr_data;
	char		*return_str;

	nbr_data.i = 0;
	nbr_data.check = 0;
	nbr_data.base = base;
	ft_nbr_base(nbr, &nbr_data);
	nbr_data.nbr_str = ft_calloc(nbr_data.len + 1, 1);
	nbr_data.check = 1;
	ft_nbr_base(nbr, &nbr_data);
	return_str = ft_strdup(nbr_data.nbr_str);
	free(nbr_data.nbr_str);
	return (return_str);
}

void	ft_nbr_base(unsigned long long nbr, t_nbr_data *nbr_data)
{
	char	*base;

	base = "0123456789abcdef";
	if ((nbr > (unsigned long long) nbr_data->base - 1))
	{
		ft_nbr_base(nbr / (unsigned long long)nbr_data->base, nbr_data);
		ft_nbr_base(nbr % (unsigned long long)nbr_data->base, nbr_data);
	}
	else
	{
		nbr += '0';
		if (nbr > '9')
			nbr = base[nbr - '0'];
		if (nbr_data->check == 0)
		{
			nbr_data->len++;
		}
		else if (nbr_data->check == 1)
		{
			nbr_data->nbr_str[nbr_data->i] = nbr;
			nbr_data->i++;
		}
	}
}

void	ft_reset_list(t_args *lstargs)
{
	lstargs->type = 0;
	lstargs->prefix = 0;
	lstargs->precision_type = 0;
	lstargs->precision_size = 0;
	lstargs->valid_arg = 0;
	lstargs->write_pre = 0;
	lstargs->sign = 0;
	lstargs->first_params.nbr = 0;
	lstargs->first_params.sign = 0;
	lstargs->first_params.check = 0;
	free(lstargs->arg);
	free(lstargs->printable_arg);
}

void	ft_final_print(t_args *lstargs)
{
	if (lstargs->precision_type == '-')
	{
		ft_putstr(lstargs->printable_arg, lstargs);
		ft_print_precision(lstargs);
	}
	else
	{
		ft_print_precision(lstargs);
		ft_putstr(lstargs->printable_arg, lstargs);
	}
}
