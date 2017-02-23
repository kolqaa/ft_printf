#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsimonov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/18 10:09:09 by nsimonov          #+#    #+#              #
#    Updated: 2017/02/22 18:49:12 by nsimonov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC =  my_bzero.c \
		fill_struct.c \
		for_nonvalid.c \
		printd.c \
		helpd.c \
		mallc_and_fill_struct.c \
		for_prec.c \
		mallc_and_fill_struct.c \
		with_mod_help.c \
		my_strlen.c \
		my_forun.c \
		for_c.c \
		for_p.c \
		for_s.c \
		is_modif.c \
		is_flag.c \
		ft_flag.c \
		ft_precision.c \
		ft_width.c \
		ft_lentgh.c \
		form_with_mod.c \
		form_without_mod.c \
		my_putstr.c \
		my_signednbr.c \
		for_d.c \
		ft_specif.c \
		my_putchar.c \
		lennum.c \
		my_formin.c \
		for_u.c \
		for_o.c \
		my_itoa_base.c \
		lennum8.c \
		lennum16.c \
		ft_atoi.c \
		ft_isdigit.c \
		my_putnbr.c \
		for_x.c \
		ft_printf.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c $(SRC) $(CFLAGS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

trash:
	rm *~