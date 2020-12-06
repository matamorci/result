/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftorrent <ftorrent@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 21:34:52 by ftorrent          #+#    #+#             */
/*   Updated: 2020/12/06 12:46:57 by ftorrent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

typedef struct{
	int		neg;
	int		zero;
	int		num;
	int		anum;
	int		punt;
	int		apunt;
	int		printcont;
	va_list	ap;
	char	*toprint;
	char	*aux;
	int		lenprint;
	int		no;
}			t_fl;

int			ft_putchar(int c);
void		ft_putnbr(int n);
int			ft_putstr(char *str, int max);
int			ft_itoa_base(intmax_t value, int base, t_fl *flags);
int			ft_itoa_base2(intmax_t value, int base, t_fl *flags);
int			ft_itoa_base3(intmax_t value, int base, t_fl *flags);
int			ft_itoa_basep(long int value, int base, t_fl *flags);
char		*ft_strmcpy(char *dest, char *src, int len, t_fl *flags);
int			ft_itoa2(int n, t_fl *flags, unsigned int i);
int			ft_itoa3(int n, t_fl *flags);
void		flagsnumd(t_fl *flags, int cont);
void		flagshexa(t_fl *flags, int cont);
void		flagshexa2(t_fl *flags, int cont);
void		flagspunt(t_fl *flags, int cont);
void		flagsstr(t_fl *flags, int cont);
void		flagschar(t_fl *flags);
void		flagsnumu(t_fl *flags, int cont);
void		flagsper(t_fl *flags, int cont);
void		presicio(t_fl *flags, int cont);
int			passaflag(t_fl *flags);
int			passaflag2(t_fl *flags);
int			ft_findflags(const char *str, int cont, t_fl *flags);
int			ft_findflags2(const char *str, int cont, t_fl *flags);
int			ft_findflags25(const char *str, int cont, t_fl *flags);
int			ft_findflags1(const char *str, int cont, t_fl *flags);
int			ft_specfind(const char *str, t_fl *flags);
int			ptnum(t_fl *flags, int cont);
t_fl		*inflags(t_fl *flags);
void		sumalen(t_fl *flags);
void		ox(t_fl *flags, int cont);
void		od(t_fl *flags, int cont);
void		lenred(t_fl *flags, char *result,
long unsigned int value, char *radix);

#endif
