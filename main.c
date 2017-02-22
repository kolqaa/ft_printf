/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:16:01 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/22 19:30:56 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"
#include <limits.h>

int main(void)
{
	char *str = "whatif";
	char *str2 = "YOHOOOOEU";
	int r = -52;
	unsigned int r2 = 31;
	int r3 = 0;
	unsigned long int s;
	char *str3;

	printf("or_prf%d\n",printf("%ju", 4999999999));
	printf("my_prf%d\n",ft_printf("%ju", 4999999999));
	return (0);
}
