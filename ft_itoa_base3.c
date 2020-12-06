/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:32:06 by ftorrent          #+#    #+#             */
/*   Updated: 2020/12/05 22:05:22 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

int	ft_itoa_base3(intmax_t value, int base, t_fl *flags)
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
