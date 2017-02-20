/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 10:56:25 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/20 14:01:14 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_printf(const char *format, ...)
{ 
	va_list arg;
	int i;
	t_mod *mod;
	
	va_start(arg, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			mod = (t_mod *)malloc(sizeof(*mod));
			mod = my_bzero(mod);
			if (fill_struct(&format[i], mod, arg) == 1)
			{
				while (ft_isdigit(format[i]) || is_modif(format[i]) || is_flag(format[i]))	
					i++;
				form_with_mod(format[i], arg, mod);
				free(mod);
			}
			else
			{
				form_without_mod(format[i], arg);
				free(mod);
			}
		}
		else
			my_putchar(format[i]);
		i++;
	}
	va_end (arg);
	return (r_value);
}
