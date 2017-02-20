/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 18:59:10 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/10 18:05:21 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_precision(const char *format, int *i, t_mod *mod)
{
	if (format[*i] == '.')
		mod->precision = 1;
	if (format[*i] == '.' && ft_isdigit(format[*i + 1]))
	{
		(*i)++;
		mod->precNum = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
		(*i)--;
	}
	else if (format[*i] == '.' &&  ft_isdigit(format[*i + 1]) == 0)
			mod->precNum = 0;
	if (mod->precision || mod->precNum)
		return (1);
	return (0);
}
