/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 19:01:17 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/18 19:29:48 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    work_with_wmC(char nb, t_mod *mod)
{
    int tmp;
    int i;

	my_putchar(nb);
    while ((mod->width - 1) > 0)
	{
		mod->zero ? my_putchar('0') : my_putchar(' ');
        mod->width--;
	}
}

void    work_with_elseC(char nb, t_mod *mod)
{
    int tmp;
    int i;

	while ((mod->width - 1) > 0)
	{
		mod->zero ? my_putchar('0') : my_putchar(' ');
		mod->width--;

	}
	my_putchar(nb);
}

void	for_c(char format, va_list arg, t_mod *mod)
{
	char nb;

	nb = (char)va_arg(arg, int);
	if ((mod->width || mod->wildcart) && (mod->min))
		work_with_wmC(nb, mod);
	else
		work_with_elseC(nb, mod);
}
