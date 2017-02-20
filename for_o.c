/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_o.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:27:27 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/19 12:31:31 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    work_with_wmO(unsigned long nb, t_mod *mod, char format)
{
    unsigned long tmp;
    int flag;

    if (mod->precNum > lennum8(nb))
        tmp = mod->precNum;
    else
        tmp = lennum8(nb);
    while (mod->precNum-- > lennum8(nb))
        my_putchar('0');
	if (mod->okto && mod->min)
	{
		my_putchar('0');
		tmp = tmp + 1;
	}
    my_itoa_base(nb, 8, format);
    while (mod->width-- > tmp)
        my_putchar(' ');
}

void    work_with_elseO(unsigned long nb, t_mod *mod, char format)
{
    unsigned int tmp;
    int flag;

    flag = 0;
    if (mod->precNum == 0 && nb == 0 && mod->precision)
    {
        flag = 1;
        tmp = 0;
	}
    else if  (mod->precNum > lennum8(nb))
        tmp = mod->precNum;
    else
        tmp = lennum8(nb);
	if (mod->okto && nb != 0 && mod->precision != 1)
		tmp++;
    while (mod->width-- > tmp)
        mod->zero ? my_putchar('0') : my_putchar(' ');
    while ((mod->precNum - lennum8(nb)) > 0)
    {
        my_putchar('0');
        mod->precNum--;
    }
    if ((!flag) || (mod->okto && mod->precision))
	{
		if (mod->okto && mod->precision == 0)
			my_putchar('0');
        my_itoa_base(nb, 8, format);
	}
}

void    for_o(char format, va_list arg, t_mod *mod)
{
    long long nb;
    nb = 0;
    if (mod->hh)
        nb = (unsigned char)va_arg(arg, int);
    else if (mod->l || format == 'O')
        nb = va_arg(arg, unsigned long int);
    else if (mod->h)
        nb = (unsigned short int)va_arg(arg, int);
    else if (mod->ll)
        nb = va_arg(arg, unsigned long long int);
    else if (mod->j)
        nb = (uintmax_t)va_arg(arg, int);
    else if (mod->z)
        nb = (size_t)va_arg(arg, int);
    else
        nb = va_arg(arg, unsigned int);
    if ((mod->width || mod->wildcart) && (mod->min))
        work_with_wmO(nb, mod, format);
    else
        work_with_elseO(nb, mod, format);
}
