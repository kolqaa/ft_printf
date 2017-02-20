/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:10:12 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/09 15:07:46 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_width(const char *format, int *i, t_mod *mod)
{
	if (ft_isdigit(format[*i]) == 1)
		{
			mod->width = ft_atoi(&format[*i]);
			while (ft_isdigit(format[*i]) == 1)
				(*i)++;
			(*i)--;
		}
	if (format[*i] == '*')
		mod->wildcart = 1;
	if (mod->width || mod->wildcart)
	{
		//printf("WIDTH RET 1\n");
		return (1);
	}
	//printf("WIDTH NOTHING\n");
	return (0);
}
