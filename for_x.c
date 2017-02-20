/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 18:30:51 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/19 14:22:48 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    work_with_wmX(long long nb, t_mod *mod, char format)
{
    long long tmp;
    int flag;
    if (mod->precNum > lennum16(nb))
        tmp = mod->precNum;
    else
        tmp = lennum16(nb);
	if (mod->okto && nb != 0)
	{
		my_putstr((format == 'X' ? "0X" : "0x"));
		tmp = tmp + 2;
	}
    while (mod->precNum-- > lennum16(nb))
        my_putchar('0');
    my_itoa_base(nb, 16, format);
    while (mod->width-- > tmp)
        my_putchar(' ');
}

void    work_with_elseX(long long nb, t_mod *mod, char format)
{
    long long tmp;
    int flag;

    flag = 0;
    if (mod->precNum == 0 && nb == 0 && mod->precision)
    {
        flag = 1;
        tmp = 0;
    }
    else if (mod->precNum > lennum16(nb))
        tmp = mod->precNum;
    else
        tmp = lennum16(nb);
    if (mod->okto && nb != 0 && mod->precision != 1)
        tmp = tmp + 2;
	if (mod->okto && mod->zero)
		my_putstr((format == 'X' ? "0X" : "0x"));
    while (mod->width-- > tmp)
		mod->zero ? my_putchar('0') : my_putchar(' ');
    while ((mod->precNum - lennum16(nb)) > 0)
    {
        my_putchar('0');
        mod->precNum--;
    }
    //if (mod->precNum == 0 && nb == 0 && mod->precision && mod->okto)
	//flag = 0;
	//else if (mod->okto && mod->width == 0 && mod->precision == 0)
	//flag = 0;
    if (mod->okto && !mod->zero && nb != 0)
		my_putstr((format == 'X' ? "0X" : "0x"));
    if (!flag)
        my_itoa_base(nb, 16, format);
}

void    for_x(char format, va_list arg, t_mod *mod)
{
    long long nb;
    nb = 0;
    if (mod->hh)
        nb = (unsigned char)va_arg(arg, int);
    else if (mod->l || format == 'X')
        nb = va_arg(arg, unsigned long int);
    else if (mod->h)
        nb = (unsigned short int)va_arg(arg, int);
    else if (mod->ll)
        nb = va_arg(arg, unsigned long long int);
    else if (mod->j)
        nb = (intmax_t)va_arg(arg, intmax_t);
    else if (mod->z)
        nb = (size_t)va_arg(arg, size_t);
    else
        nb = va_arg(arg, unsigned int);
    if ((mod->width || mod->wildcart) && (mod->min))
        work_with_wmX(nb, mod, format);
    else
        work_with_elseX(nb, mod, format);
}
