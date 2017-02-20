/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 13:16:01 by nsimonov          #+#    #+#             */
/*   Updated: 2017/02/20 14:16:23 by nsimonov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"

int main(void)
{
	char *str = "whatif";
	char *str2 = "YOHOOOOEU";
	int r = -52;
	unsigned int r2 = 31;
	int r3 = 0;
	printf("or_prf%d\n",printf("31 %n 31", &r2)); 
	printf("OR %u\n", r2);
	printf("my_prf%d\n",ft_printf("31 %n 31", &r2));
	printf("MY %u\n", r2);
	return (0);
}
