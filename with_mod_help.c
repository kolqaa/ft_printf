/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_mod_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 18:05:57 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/20 18:48:22 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	with_mod_help(const char *format, int *i, va_list arg, t_mod *mod)
{
	while (ft_isdigit(format[*i]) || is_modif(format[*i]) || is_flag(format[*i]))
		(*i)++;
	form_with_mod(format[*i], arg, mod);
}
