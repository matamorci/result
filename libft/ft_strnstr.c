/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:13:20 by ftorrent          #+#    #+#             */
/*   Updated: 2020/10/26 19:56:05 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	c;
	int	a;

	c = 0;
	if (!little[0])
		return ((char*)big);
	while (c < (int)len && big[c] != '\0')
	{
		a = 0;
		if (big[c] == little[a])
		{
			while (big[c + a] && (c + a) < (int)len)
			{
				if (big[c + a] != little[a])
					break ;
				++a;
			}
			if (!little[a])
				return ((char*)(big + c));
		}
		++c;
	}
	return (0);
}
