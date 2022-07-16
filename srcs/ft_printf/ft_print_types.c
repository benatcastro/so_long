/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:24:39 by bena              #+#    #+#             */
/*   Updated: 2022/05/16 14:27:12 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	c(t_args *lstargs)
{
	char	c;
	char	*c_str;

	c_str = NULL;
	c = va_arg(lstargs->variatic_arg, unsigned int);
	if (c != 0)
	{
		c_str = malloc(2);
		c_str[0] = c;
		c_str[1] = '\0';
	}
	else if (c == 0)
	{
		c_str = malloc(1);
		c_str[0] = '\0';
	}
	lstargs->printable_arg = c_str;
}

void	s(t_args *lstargs)
{
	char	*s;

	s = ft_strdup(va_arg(lstargs->variatic_arg, char *));
	if (s == NULL)
	{
		s = ft_strdup("(null)");
	}
	if (!s[0])
		s[0] = 0;
	lstargs->printable_arg = s;
}

void	x(t_args *lstargs)
{
	char	*hexa_nbr;

	hexa_nbr = ft_itoa_base(va_arg(lstargs->variatic_arg, unsigned int), 16);
	lstargs->printable_arg = hexa_nbr;
}

void	upper_x(t_args *lstargs)
{
	char	*hexa_nbr;
	int		i;

	i = -1;
	hexa_nbr = ft_itoa_base(va_arg(lstargs->variatic_arg, unsigned int), 16);
	while (hexa_nbr[++i])
		hexa_nbr[i] = ft_toupper(hexa_nbr[i]);
	lstargs->printable_arg = hexa_nbr;
}

void	d(t_args *lstargs)
{
	int	nbr;

	nbr = va_arg(lstargs->variatic_arg, int);
	lstargs->printable_arg = ft_itoa(nbr);
}
