/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:14:52 by becastro          #+#    #+#             */
/*   Updated: 2022/05/21 11:32:50 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(unsigned char c, t_args *lstargs)
{
	write(1, &c, 1);
	lstargs->args_size++;
}

void	ft_putstr(char *s, t_args *lstargs)
{
	size_t	i;

	if (s[0] == 0 && lstargs->type == 'c')
		ft_putchar(0, lstargs);
	else if (s[0] == 0 && lstargs->type == 's')
		write(1, 0, 0);
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i], lstargs);
		i++;
	}
}

void	*ft_getfnc(t_args *lstargs)
{
	if (lstargs->type == 'c')
		return (&c);
	else if (lstargs->type == 's')
		return (&s);
	else if (lstargs->type == 'p')
		return (&p);
	else if (lstargs->type == 'd')
		return (&d);
	else if (lstargs->type == 'i')
		return (&d);
	else if (lstargs->type == 'u')
		return (&u);
	else if (lstargs->type == 'x')
		return (&x);
	else if (lstargs->type == 'X')
		return (&upper_x);
	else if (lstargs->type == '%')
		return (&percent);
	return (0);
}

void	ft_call(void (*f)(t_args*), t_args *lstargs)
{
	f(lstargs);
}

char	*ft_trim_arg(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && is_in_types(str[i]))
		i++;
	return (ft_substr(str, 0, i + 1));
}
