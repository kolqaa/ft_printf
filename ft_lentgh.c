/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lentgh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 19:14:06 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/06 19:04:05 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_lentgh(const char *format, int *i, t_mod *mod)
{
		if (format[*i] == 'h')
			mod->h = 1;
		if (format[*i] == 'h' && format[*i + 1] == 'h')
			mod->hh = 1;
		if (format[*i] == 'j')
			mod->j = 1;
		if (format[*i] == 'z')
			mod->z = 1;
		if (format[*i] == 'l')
			mod->l = 1;
		if (format[*i] == 'l' && format[*i + 1] == 'l')
			mod->ll = 1;
	if (mod->h || mod->hh || mod->l || mod->ll || mod->j || mod->z)
	{
		//printf("LENTGH RET 1\n");
		return (1);
	}
	//printf("LENTGH NOTHING\n");
	return (0);
}
