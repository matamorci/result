/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 13:10:18 by ftorrent          #+#    #+#             */
/*   Updated: 2020/10/27 13:22:05 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t count;

	if (n == 0)
		return (0);
	count = 0;
	while (s1[count] == s2[count] && s1[count] != '\0' && count < n - 1)
	{
		count++;
	}
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
