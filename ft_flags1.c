/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:03:23 by ftorrent          #+#    #+#             */
/*   Updated: 2020/12/06 11:50:09 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ptnum(t_fl *flags, int cont)
{
	if ((flags->zero && !flags->neg) && (flags->punt == -1))
	{
		while (cont < (flags->num - flags->lenprint))
		{
			ft_putchar('0');
			++cont;
		}
	}
	else if ((!flags->zero || flags->neg) || (flags->punt != -1))
	{
		while (cont < (flags->num - flags->lenprint))
		{
			ft_putchar(' ');
			++cont;
		}
	}
	return (cont);
}

void	flagsnumd(t_fl *flags, int cont)
{
	passaflag(flags);
	ft_itoa2(va_arg(flags->ap, int), flags, 0);
	flags->lenprint = ft_strlen(flags->toprint);
	presicio(flags, 0);
	flags->lenprint = ft_strlen(flags->toprint);
	if (flags->punt < 0)
		flags->punt = -1;
	else if (flags->punt != -1)
		flags->zero = 0;
	if (flags->neg)
		ft_putstr(flags->toprint, -1);
	if (flags->toprint[0] == '-' && flags->zero && !flags->neg)
	{
		ft_putchar('-');
		++cont;
		--flags->lenprint;
		ft_strmcpy(flags->toprint, flags->toprint + 1, 1000, flags);
	}
	cont = ptnum(flags, cont);
	if (!flags->neg)
		ft_putstr(flags->toprint, -1);
	sumalen(flags);
}

void	flagshexa(t_fl *flags, int cont)
{
	passaflag(flags);
	if (flags->punt != -1)
		flags->zero = 0;
	ft_itoa_base(va_arg(flags->ap, unsigned int), 16, flags);
	flags->lenprint = ft_strlen(flags->toprint);
	presicio(flags, 0);
	flags->lenprint = ft_strlen(flags->toprint);
	if (flags->neg)
		ft_putstr(flags->toprint, -1);
	if (flags->zero && !flags->neg)
	{
		while (cont < (flags->num - flags->lenprint))
		{
			ft_putchar('0');
			++cont;
		}
	}
	else if (!flags->zero || flags->neg)
	{
		while (cont++ < (flags->num - flags->lenprint))
			ft_putchar(' ');
	}
	if (!flags->neg)
		ft_putstr(flags->toprint, -1);
	sumalen(flags);
}

void	flagsnumu(t_fl *flags, int cont)
{
	passaflag(flags);
	ft_itoa3(va_arg(flags->ap, unsigned int), flags);
	flags->lenprint = ft_strlen(flags->toprint);
	presicio(flags, 0);
	flags->lenprint = ft_strlen(flags->toprint);
	if (flags->punt < 0)
		flags->punt = -1;
	else if (flags->punt != -1)
		flags->zero = 0;
	if (flags->neg)
		ft_putstr(flags->toprint, -1);
	if (flags->toprint[0] == '-' && flags->zero && !flags->neg)
	{
		ft_putchar('-');
		++cont;
		--flags->lenprint;
		ft_strmcpy(flags->toprint, flags->toprint + 1, 1000, flags);
	}
	cont = ptnum(flags, cont);
	if (!flags->neg)
		ft_putstr(flags->toprint, -1);
	sumalen(flags);
}

void	flagshexa2(t_fl *flags, int cont)
{
	passaflag(flags);
	if (flags->punt != -1)
		flags->zero = 0;
	ft_itoa_base2(va_arg(flags->ap, unsigned int), 16, flags);
	flags->lenprint = ft_strlen(flags->toprint);
	presicio(flags, 0);
	flags->lenprint = ft_strlen(flags->toprint);
	if (flags->neg)
		ft_putstr(flags->toprint, -1);
	if (flags->zero && !flags->neg)
	{
		while (cont < (flags->num - flags->lenprint))
		{
			ft_putchar('0');
			++cont;
		}
	}
	else if (!flags->zero || flags->neg)
	{
		while (cont++ < (flags->num - flags->lenprint))
			ft_putchar(' ');
	}
	if (!flags->neg)
		ft_putstr(flags->toprint, -1);
	sumalen(flags);
}
