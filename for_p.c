/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:37:00 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/21 16:31:45 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    work_with_wmP(long long nb, t_mod *mod, char format)
{
    long long tmp;
    int flag;

    if (mod->precNum > lennum16(nb))
		nb == 0 ? (tmp = mod->precNum + 1) : \
			(tmp = mod->precNum + 2);
    else
		nb == 0 ? (tmp = lennum16(nb) + 1) : \
			(tmp = lennum16(nb) + 2);
	my_putstr("0x");
    while (mod->precNum-- > lennum16(nb))
        my_putchar('0');
    my_itoa_base(nb, 16, format);
    while (mod->width-- > tmp)
        my_putchar(' ');
}


void    work_with_elseP(long long nb, t_mod *mod, char format)
{
    long long tmp;
	int flag;

	flag = 0;
	if (nb == NULL)
		flag = 1;
    if (mod->precNum > lennum16(nb))
		nb == 0 ? (tmp = mod->precNum + 1) : \
			(tmp = mod->precNum + 2);
    else
		nb == 0 ? (tmp = lennum16(nb) + 1) :	\
			(tmp = lennum16(nb) + 2);
    if (mod->okto && nb != 0 && mod->precision != 1)
        tmp = tmp + 2;

    while (mod->width-- > tmp)
		my_putchar(' ');
    while ((mod->precNum - lennum16(nb)) > 0)
    {
        my_putchar('0');
        mod->precNum--;
    }
	my_putstr("0x");
	my_itoa_base(nb, 16, format);
}

void    for_p(char format, va_list arg, t_mod *mod)
{
    long long nb;

	nb = va_arg(arg, unsigned long);
    if ((mod->width || mod->wildcart) && (mod->min))
        work_with_wmP(nb, mod, format);
    else
        work_with_elseP(nb, mod, format);
}
