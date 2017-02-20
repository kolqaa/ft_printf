/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:03:45 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/05 20:42:19 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int if_specif(char format)
{
	if (format == 's' || format == 'S' || format == 'd' || 
		format == 'i' || format == 'p' || format == 'D' || 
		format == 'c' || format == 'C' || format == 'o' ||
		format == 'u' || format == 'U' || format == 'x' ||
		format == 'X' || format == 'O')
		return (1);
	return (0);
}
