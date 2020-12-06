/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:50:23 by ftorrent          #+#    #+#             */
/*   Updated: 2020/12/05 22:06:45 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(int n)
{
	char c;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = -n;
			ft_putnbr(n);
		}
		else if (n < 10)
		{
			c = n + '0';
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(n / 10);
			c = (n % 10) + '0';
			write(1, &c, 1);
		}
	}
}

int		ft_putstr(char *str, int max)
{
	int cont;

	cont = 0;
	while ((cont < max || max < 0) && str[cont])
	{
		ft_putchar(str[cont]);
		++cont;
	}
	return (cont);
}
