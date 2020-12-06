/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:04:45 by ftorrent          #+#    #+#             */
/*   Updated: 2020/12/06 00:16:21 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flagschar(t_fl *flags)
{
	int cont;

	cont = 0;
	passaflag(flags);
	*flags->toprint = va_arg(flags->ap, int);
	if (flags->neg)
		ft_putchar((flags->toprint)[0]);
	if (flags->zero && !flags->neg)
	{
		while ((cont++) + 1 < flags->num)
			ft_putchar('0');
	}
	else if (!flags->zero || flags->neg)
	{
		while ((cont++) + 1 < flags->num)
			ft_putchar(' ');
	}
	if (!flags->neg)
		ft_putchar((flags->toprint)[0]);
	sumalen(flags);
	if (flags->num == 0)
		++flags->printcont;
}

void	flagsstr(t_fl *flags, int cont)
{
	passaflag2(flags);
	ft_strmcpy(flags->toprint, va_arg(flags->ap, char*), 10000, flags);
	if ((size_t)flags->punt < ft_strlen(flags->toprint))
		flags->toprint[flags->punt] = '\0';
	flags->lenprint = ft_strlen(flags->toprint);
	if (flags->neg)
		ft_putstr(flags->toprint, flags->punt);
	if (flags->zero && !flags->neg)
	{
		while ((cont++) < (flags->num - flags->lenprint))
			ft_putchar('0');
	}
	else if (!flags->zero || flags->neg)
	{
		while ((cont++) < (flags->num - flags->lenprint))
			ft_putchar(' ');
	}
	if (!flags->neg)
		ft_putstr(flags->toprint, flags->punt);
	sumalen(flags);
}

int		presicio2(t_fl *flags, int cont)
{
	if (flags->num > flags->lenprint && flags->zero
	&& !flags->punt && flags->no && !flags->neg)
	{
		while (cont < (flags->num - flags->lenprint))
			flags->toprint[cont++] = '0';
		ft_strmcpy(flags->toprint + cont, flags->aux, 2000, flags);
		flags->toprint[flags->lenprint + cont] = '\0';
	}
	if (flags->punt > flags->lenprint)
	{
		while (cont < (flags->punt - flags->lenprint))
			flags->toprint[cont++] = '0';
		ft_strmcpy(flags->toprint + cont, flags->aux, 2000, flags);
		flags->toprint[flags->lenprint + cont] = '\0';
	}
	return (cont);
}

void	presicio(t_fl *flags, int cont)
{
	flags->aux = ft_calloc(2000, 1);
	if (flags->toprint[0] == '-')
	{
		ft_strmcpy(flags->aux, flags->toprint + 1, 2000, flags);
		++cont;
		++flags->punt;
		--flags->lenprint;
		++flags->no;
	}
	else
		ft_strmcpy(flags->aux, flags->toprint, 2000, flags);
	if (flags->punt == 0 && flags->lenprint == 1 && flags->toprint[0] == '0')
	{
		flags->lenprint = 0;
		flags->toprint[0] = '\0';
	}
	cont = presicio2(flags, cont);
	free(flags->aux);
}

void	flagspunt(t_fl *flags, int cont)
{
	passaflag(flags);
	flags->lenprint = 1;
	ft_itoa_basep(va_arg(flags->ap, unsigned long int), 16, flags);
	flags->lenprint = ft_strlen(flags->toprint);
	ox(flags, 2);
	flags->lenprint = ft_strlen(flags->toprint);
	if (flags->neg)
		ft_putstr(flags->toprint, -1);
	if (flags->zero && !flags->neg)
	{
		while ((cont++) < (flags->num - flags->lenprint))
			ft_putchar('0');
	}
	else if (!flags->zero || flags->neg)
	{
		while ((cont++) < (flags->num - flags->lenprint))
			ft_putchar(' ');
	}
	if (!flags->neg)
		ft_putstr(flags->toprint, -1);
	sumalen(flags);
}
