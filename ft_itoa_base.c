/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:10:15 by ftorrent          #+#    #+#             */
/*   Updated: 2020/12/06 12:33:15 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

int		ft_itoa_base(intmax_t value, int base, t_fl *flags)
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
	radix = ft_strdup("0123456789abcdef");
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

void	sumalen(t_fl *flags)
{
	if (flags->num > flags->lenprint)
		flags->printcont += flags->num;
	else
		flags->printcont += flags->lenprint;
}

int		ft_itoa_basep(long int value, int base, t_fl *flags)
{
	long unsigned int	value2;
	char				*radix;
	char				*result;

	if (!value)
	{
		ft_strmcpy(flags->toprint, "0x0\0", 100, flags);
		return (5);
	}
	if (value < 0)
		value = value * -1;
	value2 = value;
	while (value2 /= base)
		flags->lenprint++;
	if ((result = (char*)malloc(sizeof(char) * (flags->lenprint + 1))) == NULL)
		return (0);
	radix = ft_strdup("0123456789abcdef");
	result[flags->lenprint] = '\0';
	lenred(flags, result, value, radix);
	flags->lenprint = ft_strlen(result);
	ft_strmcpy(flags->toprint, result, flags->lenprint, flags);
	free(radix);
	free(result);
	return (flags->lenprint);
}

void	lenred(t_fl *flags, char *result, long unsigned int value, char *radix)
{
	while (flags->lenprint-- > 0)
	{
		result[flags->lenprint] = radix[value % 16];
		value /= 16;
	}
}
