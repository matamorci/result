/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:07:44 by ftorrent          #+#    #+#             */
/*   Updated: 2020/10/28 11:52:47 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *nptr)
{
	size_t	i;
	char	n;
	size_t	out;

	i = 0;
	out = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		n = nptr[i++];
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		out = out * 10 + nptr[i] - 48;
		i++;
	}
	if (n == '-')
		out = -out;
	return (out);
}
