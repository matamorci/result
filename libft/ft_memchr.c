/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:11:27 by ftorrent          #+#    #+#             */
/*   Updated: 2020/10/26 19:51:38 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	int		n;
	char	*pt;

	pt = (char*)ptr;
	n = 0;
	while (n < (int)num)
	{
		if (pt[n] == (char)value)
			return (pt + n);
		++n;
	}
	return (0);
}
