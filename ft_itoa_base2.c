/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:30:28 by ftorrent          #+#    #+#             */
/*   Updated: 2020/12/05 22:05:07 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

int		ft_itoa_base2(intmax_t value, int base, t_fl *flags)
{
	intmax_t	value2;
	char		*radix;
	char		*result;

	flags->lenprint = 1;
	value2 = value;
	while (value2 /= base)
		flags->lenprint++;
	if ((result = (char*)malloc(sizeof(char) * (flags->lenprint + 1))) == NULL)
		return (0);
	radix = ft_strdup("0123456789ABCDEF");
	result[flags->lenprint] = '\0';
	while (flags->lenprint-- > 0)
	{
		result[flags->lenprint] = radix[value % base];
		value /= base;
	}
	flags->lenprint = ft_strlen(result);
	ft_strmcpy(flags->toprint, result, flags->lenprint, flags);
	free(radix);
	free(result);
	return (flags->lenprint);
}

void	flagsper(t_fl *flags, int cont)
{
	passaflag(flags);
	if (flags->neg)
		ft_putchar('%');
	if (flags->neg && flags->zero)
		flags->zero = 0;
	if (flags->zero && flags->num)
	{
		while (cont++ < flags->num - 1)
			ft_putchar('0');
		flags->printcont += cont - 1;
	}
	else if (!flags->zero && flags->num)
	{
		while (cont++ < flags->num - 1)
			ft_putchar(' ');
		flags->printcont += cont - 1;
	}
	if (!flags->neg)
		ft_putchar('%');
	++flags->printcont;
}
