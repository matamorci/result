/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:08:50 by ftorrent          #+#    #+#             */
/*   Updated: 2020/10/26 19:52:05 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*src;
	unsigned char	*dest;
	int				n;
	unsigned int	cont;

	cont = 0;
	n = 0;
	src = (unsigned char*)ptr1;
	dest = (unsigned char*)ptr2;
	while (cont < num)
	{
		if (src[cont] == dest[cont])
		{
		}
		else
		{
			n = src[cont] - dest[cont];
			return (n);
		}
		++cont;
	}
	return (n);
}
