/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_prec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 09:35:04 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/19 10:00:05 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    work_with_wmPr(char nb, t_mod *mod)
{
    int tmp;
    int i;

    my_putchar('%');
    while ((mod->width - 1) > 0)
    {
        mod->zero ? my_putchar('0') : my_putchar(' ');
        mod->width--;
    }
}

void    work_with_elsePr(char nb, t_mod *mod)
{
    int tmp;
    int i;

    while ((mod->width - 1) > 0)
    {
        mod->zero ? my_putchar('0') : my_putchar(' ');
        mod->width--;

    }
    my_putchar('%');
}

void    for_prec(char format, va_list arg, t_mod *mod)
{
    if ((mod->width || mod->wildcart) && (mod->min))
        work_with_wmPr(format, mod);
    else
        work_with_elsePr(format, mod);
}