/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:07:21 by ftorrent          #+#    #+#             */
/*   Updated: 2020/12/06 11:50:46 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		passaflag(t_fl *flags)
{
	if (flags->anum)
	{
		flags->num = va_arg(flags->ap, int);
		if (flags->num < 0)
		{
			flags->neg = 1;
			flags->num = flags->num * (-1);
		}
	}
	if (flags->apunt)
		flags->punt = va_arg(flags->ap, int);
	return (ft_strlen(flags->toprint));
}

int		passaflag2(t_fl *flags)
{
	if (flags->anum)
	{
		flags->num = va_arg(flags->ap, int);
		if (flags->num < 0)
		{
			flags->neg = 1;
			flags->num = flags->num * (-1);
		}
	}
	if (flags->apunt)
		flags->punt = va_arg(flags->ap, int);
	return (ft_strlen(flags->toprint));
}

t_fl	*inflags(t_fl *flags)
{
	free(flags->toprint);
	flags->neg = 0;
	flags->zero = 0;
	flags->num = 0;
	flags->anum = 0;
	flags->punt = -1;
	flags->apunt = 0;
	flags->toprint = ft_calloc(9000, 1);
	flags->lenprint = 0;
	flags->no = 0;
	return (flags);
}

void	ox(t_fl *flags, int cont)
{
	if (!flags->punt)
		flags->toprint[2] = '\0';
	if ((flags->toprint[0] == '0') &&
	(flags->toprint[1] == 'x') && (flags->toprint[2] == '0')
	&& (!flags->toprint[3]))
	{
		if (flags->punt)
		{
			while ((cont) - 2 < flags->punt)
			{
				flags->toprint[cont] = '0';
				cont++;
			}
		}
		return ;
	}
	flags->aux = ft_calloc(1000, 1);
	ft_strmcpy(flags->aux, flags->toprint, 1000, flags);
	od(flags, cont);
	free(flags->aux);
}

void	od(t_fl *flags, int cont)
{
	flags->toprint[0] = '0';
	flags->toprint[1] = 'x';
	if (flags->punt)
	{
		while ((cont) - 2 < flags->punt - flags->lenprint)
		{
			flags->toprint[cont] = '0';
			++cont;
		}
	}
	if (flags->punt != 0)
		ft_strmcpy(flags->toprint + cont, flags->aux, 1000, flags);
}
