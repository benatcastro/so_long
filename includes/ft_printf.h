/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:48:19 by becastro          #+#    #+#             */
/*   Updated: 2022/07/12 23:59:10 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"
# define LONG_MAX 9223372036854775807LL
# define LONG_MIN -9223372036854775808
# define ULONG_MAX 18446744073709551615ULL

typedef struct t_f_width
{
	int			nbr;
	char		sign;
	int			check;
}	t_f_width;

typedef struct t_args
{
	char		*arg;
	char		*printable_arg;
	char		sign;
	int			arg_len;
	char		type;
	char		prefix;
	char		precision_type;
	char		precision_char;
	int			precision_size;
	int			write_pre;
	int			args_size;
	int			valid_arg;
	t_f_width	first_params;
	va_list		variatic_arg;
}	t_args;

typedef struct t_nbr_data
{
	char		*nbr_str;
	int			base;
	int			len;
	int			i;
	int			check;
}	t_nbr_data;
//validate args
int		ft_validate_arg(const char *s);
//field width
void	ft_get_field_width(t_args *lstargs);
void	ft_width_print(t_args *lstargs);
//prints
void	c(t_args *lstargs);
void	s(t_args *lstargs);
void	p(t_args *lstargs);
void	d(t_args *lstargs);
void	u(t_args *lstargs);
void	x(t_args *lstargs);
void	upper_x(t_args *lstargs);
void	percent(t_args *lstargs);
//conversionsi
char	*ft_itoa_base(unsigned long long nbr, int base);
void	ft_nbr_base(unsigned long long nbr, t_nbr_data *t_hexa_data);
//precision printers
void	ft_print_precision(t_args *lstargs);
void	ft_print_prefix(t_args *lstargs);
void	ft_print_dot(t_args *lstargs);
void	ft_print_zero(t_args *lstargs);
void	ft_print_minus(t_args *lstargs);
void	ft_print_sign(t_args *lstargs);
//other fncs
void	*ft_getfnc(t_args *lstargs);
void	ft_call(void (*f)(t_args*), t_args *lstargs);
int		ft_print_argument(t_args *lstargs);
//getting flags
t_args	*ft_getflags(t_args *lstargs);
int		ft_is_arg(const char *s);
void	ft_get_prefix(t_args *lstargs, char c);
void	ft_get_precision(t_args *lstargs, char *arg);
void	ft_get_precision_size(t_args *lstargs, char *str);
//checking flags
int		is_in_types(char s);
int		is_in_prefix(char c);
int		is_in_precision(char c);
//utils
void	ft_putchar(unsigned char c, t_args *lstargs);
void	ft_putstr(char *s, t_args *lstargs);
char	*ft_trim_arg(char *str);
void	ft_reset_list(t_args *lstargs);
void	test(t_args *lstargs);
int		ft_printf(const char *str, ...);
int		ft_to_positive(int nbr);
void	ft_final_print(t_args *lstargs);
int		get_i_int(t_args *lstargs, int i, int arg_len, int p_size);
void	ft_iterate(char *str, t_args *lstargs);
#endif
