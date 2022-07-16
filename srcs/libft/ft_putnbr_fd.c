/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:34:03 by becastro          #+#    #+#             */
/*   Updated: 2022/04/27 14:53:28 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nbr(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_nbr(n / 10, fd);
		ft_nbr(n % 10, fd);
	}
	else
	{
		n = n + '0';
		write(fd, &n, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = ((unsigned int)(-n));
		write(fd, "-", 1);
		ft_nbr(nbr, fd);
	}
	else
	{
		nbr = (unsigned int)n;
		ft_nbr(nbr, fd);
	}
}
