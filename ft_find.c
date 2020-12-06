/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:02:48 by ftorrent          #+#    #+#             */
/*   Updated: 2020/12/06 12:29:52 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_findflags25(const char *str, int cont, t_fl *flags)
{
	if ((str[cont + 2] >= '0') && (str[cont + 2] <= '9'))
	{
		flags->punt = (((str[cont + 1] - 48) * 10) + str[cont + 2] - 48);
		if ((str[cont + 3] >= '0') && (str[cont + 3] <= '9'))
		{
			flags->punt = (flags->punt * 10) + (str[cont + 3] - 48);
			++cont;
		}
		cont = cont + 2;
	}
	else
	{
		flags->punt = str[cont + 1] - 48;
		++cont;
	}
	return (cont);
}

int		ft_findflags2(const char *str, int cont, t_fl *flags)
{
	if (str[cont] == '*')
	{
		flags->anum = 1;
		++cont;
	}
	if (str[cont] == '.')
	{
		if ((str[cont + 1] >= '0') && (str[cont + 1] <= '9'))
			cont = ft_findflags25(str, cont, flags);
		else if (str[cont + 1] == '*')
		{
			flags->apunt = 1;
			++cont;
		}
		else
			flags->punt = 0;
		++cont;
	}
	return (cont - 1);
}

int		ft_findflags1(const char *str, int cont, t_fl *flags)
{
	if ((str[cont] >= '0') && (str[cont] <= '9'))
	{
		if ((str[cont + 1] >= '0') && (str[cont + 1] <= '9'))
		{
			flags->num = (((str[cont] - 48) * 10) + str[cont + 1] - 48);
			if ((str[cont + 2] >= '0') && (str[cont + 2] <= '9'))
			{
				flags->num = (flags->num * 10) + (str[cont + 2] - 48);
				++cont;
			}
			cont = cont + 2;
		}
		else
		{
			flags->num = str[cont] - 48;
			++cont;
		}
	}
	return (cont);
}

int		ft_findflags(const char *str, int cont, t_fl *flags)
{
	if (str[cont] == '-')
	{
		flags->neg = 1;
		++cont;
		while (str[cont] == '-')
			++cont;
	}
	if (str[cont] == '0')
	{
		flags->zero = 1;
		++cont;
		while (str[cont] == '0')
			++cont;
	}
	if (str[cont] == '-')
	{
		flags->neg = 1;
		++cont;
		while (str[cont] == '-')
			++cont;
	}
	cont = ft_findflags1(str, cont, flags);
	return (ft_findflags2(str, cont, flags));
}

int		ft_specfind(const char *str, t_fl *flags)
{
	int		cont;
	_Bool	spec;

	spec = 1;
	cont = 1;
	inflags(flags);
	while (spec)
	{
		if (str[cont] == '0' || str[cont] == '-' || str[cont] == '.'
		|| ((str[cont] >= '1') && (str[cont] <= '9')) || (str[cont] == '*'))
			cont += ft_findflags(str, 1, flags);
		if (str[cont] == 'c' || str[cont] == 's' || str[cont] == 'p'
		|| str[cont] == 'd' || str[cont] == 'i' || str[cont] == 'u'
		|| str[cont] == 'x' || str[cont] == 'X' || str[cont] == '%')
			return (cont);
		else
			return (0);
		++cont;
	}
	return (0);
}
