/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 06:12:13 by bena              #+#    #+#             */
/*   Updated: 2022/05/14 06:26:22 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	p(t_args *lstargs)
{
	long long			pointer;
	char				*aux;
	char				*ptr;

	pointer = va_arg(lstargs->variatic_arg, unsigned long long);
	aux = ft_itoa_base(pointer, 16);
	ptr = ft_strjoin("0x", aux);
	lstargs->printable_arg = ptr;
	free(aux);
}

void	percent(t_args *lstargs)
{
	char	*c_str;

	c_str = malloc(2);
	c_str[0] = '%';
	c_str[1] = '\0';
	lstargs->printable_arg = c_str;
}

void	u(t_args *lstargs)
{
	unsigned int	nbr;

	nbr = va_arg(lstargs->variatic_arg, unsigned int);
	lstargs->printable_arg = ft_itoa_base(nbr, 10);
}
