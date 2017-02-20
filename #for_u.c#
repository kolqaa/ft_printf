/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:20:34 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/19 17:26:26 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    work_with_wmU(unsigned long long nb, t_mod *mod)
{
	unsigned long long tmp;

	if (mod->precNum > lennum(nb))
		tmp = mod->precNum;
	else
		tmp = lennum(nb);
	while (mod->precNum-- > lennum(nb))
		my_putchar('0');
	my_forun(nb);
	while ((unsigned long)mod->width-- > tmp)
		my_putchar(' ');
}

void    work_with_elseU(unsigned long long nb, t_mod *mod)
{
    unsigned long long tmp;
	int flag;

	flag = 0;
	if (mod->precNum == 0 && nb == 0 && mod->precision)
	{
		flag = 1;
		tmp = 0;
	}
	if (mod->precNum > lennum(nb))
		tmp = mod->precNum;
	else
		tmp = lennum(nb);
	while ((unsigned long)mod->width-- > tmp)
		mod->zero ? my_putchar('0') : my_putchar(' ');
	while ((mod->precNum - lennum(nb)) > 0)
	{
		my_putchar('0');
		mod->precNum--;
	}
	if (!flag)
		my_forun(nb);
}

void	for_u(char format, va_list arg, t_mod *mod)
{
	unsigned long long nb;

    nb = 0;
    if (mod->hh)
        nb = (unsigned char)va_arg(arg, int);
    else if (mod->l)
        nb = va_arg(arg, unsigned long long);
    else if (mod->h || format == 'U')
        nb = (unsigned long)va_arg(arg, unsigned long);
	else if (mod->h && format == 'U')
		nb = (unsigned long)va_arg(arg, unsigned long);
    else if (mod->ll)
        nb = va_arg(arg, unsigned long long int);
    else if (mod->j)
        nb = (intmax_t)va_arg(arg, intmax_t);
    else if (mod->z)
        nb = (size_t)va_arg(arg, int);
    else
        nb = va_arg(arg, unsigned int);
	if ((mod->width || mod->wildcart) && (mod->min))
		work_with_wmU(nb, mod);
	else
		work_with_elseU(nb, mod);
}
