/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:00:01 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/19 14:27:45 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	work_with_wm(long long nb, t_mod *mod)
{
	long long tmp;
	int flag;

	if (mod->width < 0)
		mod->width *= -1;
	flag = 0;
	if (mod->precNum > lennum(nb))
		tmp = mod->precNum;
	else 
		tmp = lennum(nb);
	if (mod->precNum == 0 && nb == 0 && mod->precision)
    {
		flag = 1;
        tmp = 0;
    }
	if (mod->plu || mod->space || nb < 0)
		tmp++;
	if (nb < 0)
        my_putchar('-');
	else if (mod->plu || mod->space)
        mod->plu ? my_putchar('+') : my_putchar(' ');
	while (mod->precNum-- > lennum(nb))
		my_putchar('0');
	if (!flag)
		my_formin(nb);
	while (mod->width-- > tmp)
		my_putchar(' ');
}

void	work_with_else(long long nb, t_mod *mod)
{
	long long tmp;
	int flag;

	flag = 0;
	if (mod->precNum == 0 && nb == 0 && mod->precision) // last changes
    {
        flag = 1;
        tmp = 0;
	}
    else if (mod->precNum > lennum(nb))
        tmp = mod->precNum;
    else
        tmp = lennum(nb);
	if (mod->plu || mod->space || nb < 0)
		tmp++;
	if (nb < 0 && flag)
		my_putchar('-');
	else if ((flag && mod->plu && nb > 0) || (flag && mod->min && nb > 0))
		mod->plu ? my_putchar('+') : my_putchar('-');
	else if (flag && mod->space)
		my_putchar(' ');
	if (mod->zero && mod->plu)
		nb < 0 ? my_putchar('-') : my_putchar('+');
	else if (mod->zero && nb < 0)
		my_putchar('-');
    while (mod->width-- > tmp)
	{
		if (mod->zero && mod->precision == 0)
			my_putchar('0');
		else
			my_putchar(' ');
	}
	if (nb < 0 && !flag && mod->zero == 0)
		my_putchar('-');
	else if ((mod->plu || mod->space) && (!flag && mod->zero == 0))
		mod->plu ? my_putchar('+') : my_putchar(' ');
    while ((mod->precNum - lennum(nb)) > 0)
    {
        my_putchar('0');
        mod->precNum--;
    }
	if (!flag)
		my_formin(nb);
}

void	for_d(char format, va_list arg, t_mod *mod)
{
	long long  nb;
	nb = 0;

	if (mod->hh)
		nb = (signed char)va_arg(arg, int);
	else if (mod->l || format == 'D')
		nb = va_arg(arg, long);
	else if (mod->h)
		nb = (short)va_arg(arg, int);
	else if (mod->ll)
		nb = va_arg(arg, long long);
	else if (mod->j)
		nb = (intmax_t)va_arg(arg, intmax_t);
	else if (mod->z)
		nb = (size_t)va_arg(arg, size_t);
	else  
		nb = va_arg(arg, int);
	if ((mod->width || mod->wildcart) && (mod->min || mod->width < 0))
		work_with_wm(nb, mod);
	else
		work_with_else(nb, mod);
}
