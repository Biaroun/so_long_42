/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:45:00 by biaroun            #+#    #+#             */
/*   Updated: 2022/05/27 12:45:02 by biaroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	nbr;
	long long int	a;
	long long int	b;

	nbr = n;
	a = 0;
	b = 9;
	if (nbr < a)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr > b)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + '0', fd);
	}
	else
	{
		nbr = nbr + '0';
		ft_putchar_fd(nbr, fd);
	}
}
