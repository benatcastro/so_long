/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:57:36 by becastro          #+#    #+#             */
/*   Updated: 2022/05/21 11:43:54 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *s, ...)
{
	t_args	*lstargs;
	char	*str;
	int		aux;

	str = (char *)s;
	lstargs = ft_calloc(1, sizeof(t_args));
	va_start(lstargs->variatic_arg, s);
	ft_iterate(str, lstargs);
	va_end(lstargs->variatic_arg);
	aux = lstargs->args_size;
	free(lstargs);
	return (aux);
}

void	ft_iterate(char *str, t_args *lstargs)
{
	size_t	i;
	char	*arg;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			arg = ft_trim_arg(&str[i + 1]);
			lstargs->arg = ft_strdup(arg);
			if (ft_validate_arg(arg) == 0)
			{
				ft_putchar('%', lstargs);
				continue ;
			}
			free (arg);
			ft_getflags(lstargs);
			ft_print_argument(lstargs);
			i += ft_is_arg (&str[i + 1]);
		}
		else
			ft_putchar(str[i], lstargs);
	}
}

int	ft_print_argument(t_args *lstargs)
{
	ft_call(ft_getfnc(lstargs), lstargs);
	ft_print_prefix(lstargs);
	if (lstargs->first_params.nbr)
		ft_width_print(lstargs);
	else
		ft_final_print(lstargs);
	ft_reset_list(lstargs);
	return (0);
}

int	ft_validate_arg(const char *s)
{
	while (*s)
	{
		if (!is_in_types(*s) || !is_in_prefix(*s) || !is_in_precision(*s))
			return (1);
		s++;
	}
	return (0);
}
