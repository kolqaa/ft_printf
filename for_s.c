/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:58:33 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/20 14:17:25 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    work_with_wmS(char *nb, t_mod *mod)
{
	int tmp;
    int i;

    i = 0;
    if (mod->precNum < my_strlen(nb) && mod->precision)
        tmp = mod->precNum;
    else
        tmp = my_strlen(nb);
	if (!mod->precision)
        my_putstr(nb);
    while (mod->precNum-- && nb[i])
        my_putchar(nb[i++]);
	while (mod->width-- > tmp)
        mod->zero ? my_putchar('0') : my_putchar(' ');
}

void    work_with_elseS(char *nb, t_mod *mod)
{
	int tmp;
	int i;
	
	i = 0;
    if (mod->precNum < my_strlen(nb) && mod->precision)
        tmp = mod->precNum;
    else
        tmp = my_strlen(nb);
	while (mod->width-- > tmp)
		mod->zero ? my_putchar('0') : my_putchar(' ');
	while (mod->precNum-- && nb[i])
		my_putchar(nb[i++]);
	if (!mod->precision)
		my_putstr(nb);
}

void    for_s(char format, va_list arg, t_mod *mod)
{
    char *nb;
	
    nb = va_arg(arg, char*);
	if (nb == NULL)
		nb = "(null)";
    if ((mod->width || mod->wildcart) && (mod->min || mod->width < 0))
        work_with_wmS(nb, mod);
    else
        work_with_elseS(nb, mod);
}
