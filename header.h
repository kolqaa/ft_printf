/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:34:07 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/19 16:21:05 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

typedef struct s_mod
{
	int min;
	int plu;
	int space;
	int okto;
	int zero;
	int width;
	int precision;
	int precNum;
	int wildcart;
	int x;
	int X;
	int flag;
	int hh;
	int h;
	int l;
	int ll;
	int j;
	int z;
}			t_mod;

int     r_value;
int    ft_printf(const char *format, ...);
void    form_without_mod(char format, va_list arg);
int     form_with_mod(char format, va_list arg, t_mod *mod);
int		fill_struct(const char *fromat, t_mod *mod, va_list arg);
int		if_specif(char format);
int		ft_flag(const char *format, int *i, t_mod *mod, va_list arg);
int		ft_width(const char *format, int *i, t_mod *mod);
int		ft_precision(const char *format, int *i, t_mod *mod);
int		ft_lentgh(const char *fromat, int *i, t_mod * mod);
t_mod	*my_bzero(t_mod *mod);
int		is_modif(char format);
int		is_flag(char format);
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_signednbr(long long nbr);
int		lennum(long long  nbr);
void	my_formin(long long nbr);
void	for_d(char format, va_list arg, t_mod *mod);
void	for_u(char format, va_list arg, t_mod *mod);
void	for_o(char format, va_list arg, t_mod *mod);
void 	my_itoa_base(long long value, int base, char format);
int		lennum8(long long nbr);
int		lennum16(long long nbr);
int		ft_isdigit(int c);
int 	ft_atoi(const char *str);
void	my_putnbr(int n);
void	for_x(char fromat, va_list arg, t_mod *mod);
void	for_p(char format, va_list arg, t_mod *mod);
void	for_s(char format, va_list arg, t_mod *mod);
int		my_strlen(char *str);
void	for_c(char format, va_list arg, t_mod *mod);
void	for_prec(char format, va_list arg, t_mod *mod);
void	my_forun(long long nbr);

#endif
