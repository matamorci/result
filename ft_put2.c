/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:52:08 by ftorrent          #+#    #+#             */
/*   Updated: 2020/12/06 12:46:42 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strmcpy(char *dest, char *src, int len, t_fl *flags)
{
	int i;

	i = 0;
	if (!src)
		return (ft_strmcpy(flags->toprint, "(null)", 100, flags));
	while (src[i] != '\0' && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_nblen2(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

int			ft_itoa2(int n, t_fl *flags, unsigned int i)
{
	char			*dest;
	unsigned int	nb;

	nb = (n < 0 ? -n : n);
	flags->lenprint = ft_nblen2(nb);
	if (!(dest = (char *)malloc(sizeof(char)
	* flags->lenprint + 1 + (n < 0 ? 1 : 0))))
		return (0);
	if (n < 0)
	{
		dest[i] = '-';
		flags->lenprint++;
	}
	i = flags->lenprint - 1;
	while (nb >= 10)
	{
		dest[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	dest[i] = nb % 10 + 48;
	dest[flags->lenprint] = '\0';
	ft_strmcpy(flags->toprint, dest, flags->lenprint, flags);
	free(dest);
	return (0);
}

int			ft_itoa3(int n, t_fl *flags)
{
	char			*dest;
	unsigned int	nb;
	unsigned int	i;

	nb = n;
	flags->lenprint = ft_nblen2(nb);
	i = 0;
	if (!(dest = (char *)malloc(sizeof(char)
	* flags->lenprint + 1 + (n < 0 ? 1 : 0))))
		return (0);
	i = flags->lenprint - 1;
	while (nb >= 10)
	{
		dest[i] = nb % 10 + 48;
		nb /= 10;
		i--;
	}
	dest[i] = nb % 10 + 48;
	dest[flags->lenprint] = '\0';
	ft_strmcpy(flags->toprint, dest, flags->lenprint, flags);
	free(dest);
	return (0);
}
