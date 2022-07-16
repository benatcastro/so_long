/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:37:08 by becastro          #+#    #+#             */
/*   Updated: 2022/07/12 23:59:30 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_trim_minus(char	*arg, t_args *lstargs)
{
	char	*aux;

	lstargs->first_params.sign = '-';
	aux = ft_substr(arg, 1, ft_strlen(arg));
	free(arg);
	return (aux);
}

static void	ft_get_first_param(t_args *lstargs)
{
	char		*full_arg;
	char		*aux;
	int			i;

	full_arg = ft_strdup(lstargs->arg);
	i = 0;
	if (full_arg[0] == '-')
	{
		full_arg = ft_trim_minus(full_arg, lstargs);
	}
	while ((!is_in_precision(full_arg[i]) && full_arg[i] != '.')
		|| ft_isdigit(full_arg[i]))
		i++;
	aux = ft_substr(full_arg, 0, i);
	lstargs->first_params.nbr = ft_atoi(aux);
	free(aux);
	aux = ft_substr(full_arg, i, ft_strlen(full_arg) - i);
	free(lstargs->arg);
	lstargs->arg = ft_strdup(aux);
	free(aux);
	free(full_arg);
}

void	ft_get_field_width(t_args *lstargs)
{
	int	j;

	j = -1;
	while (lstargs->arg[++j])
	{
		if ((!ft_isdigit(lstargs->arg[j])
				&& lstargs->arg[j] != '-')
			&& lstargs->arg[j] != '.' && lstargs->arg[j] != 's')
			return ;
		else if (!is_in_types(lstargs->arg[j + 1]))
		{
			lstargs->first_params.check = 1;
		}
		else if (lstargs->arg[j] == '.' || lstargs->arg[j] == 's')
			break ;
	}
	ft_get_first_param(lstargs);
}
