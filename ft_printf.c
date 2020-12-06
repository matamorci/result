/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:33:24 by ftorrent          #+#    #+#             */
/*   Updated: 2020/12/06 12:56:08 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printype(const char *str, t_fl *flags)
{
	int		pos;

	pos = 1;
	if (!(pos = ft_specfind(str, flags)))
		return (1);
	else if (str[pos] == 'c')
		flagschar(flags);
	else if (str[pos] == 's')
		flagsstr(flags, 0);
	else if (str[pos] == 'p')
		flagspunt(flags, 0);
	else if (str[pos] == 'd' || str[pos] == 'i')
		flagsnumd(flags, 0);
	else if (str[pos] == 'u')
		flagsnumu(flags, 0);
	else if (str[pos] == 'x')
		flagshexa(flags, 0);
	else if (str[pos] == 'X')
		flagshexa2(flags, 0);
	else if (str[pos] == '%')
		flagsper(flags, 0);
	return (pos);
}

int	ft_printf(const char *str, ...)
{
	int		pos;
	t_fl	*flags;

	if (!(flags = (t_fl*)malloc(sizeof(t_fl))))
		return (0);
	inflags(flags);
	va_start(flags->ap, str);
	flags->printcont = 0;
	pos = 0;
	while (str[pos])
	{
		if (str[pos] == '%')
			pos += ft_printype(str + pos, flags);
		else
		{
			ft_putchar(str[pos]);
			flags->printcont += 1;
		}
		++pos;
	}
	va_end(flags->ap);
	pos = flags->printcont;
	free(flags->toprint);
	free(flags);
	return (pos);
}

int main()
{
	ft_printf("%c", 'a');
}
