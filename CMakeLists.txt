cmake_minimum_required(VERSION 3.6)
project(ft_printf)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        author
        fill_struct.c
        for_c.c
        for_d.c
        for_nonvalid.c
        for_o.c
        for_p.c
        for_prec.c
        for_s.c
        for_u.c
        for_x.c
        form_with_mod.c
        form_without_mod.c
        ft_atoi.c
        ft_flag.c
        ft_isdigit.c
        ft_lentgh.c
        ft_precision.c
        ft_printf.c
        ft_specif.c
        ft_width.c
        header.h
        helpd.c
        is_flag.c
        is_mod.c
        is_modif.c
        lennum.c
        lennum16.c
        lennum8.c
        main.c
        Makefile
        my_bzero.c
        my_formin.c
        my_forun.c
        my_itoa_base.c
        my_putchar.c
        my_putnbr.c
        my_putstr.c
        my_signednbr.c
        my_strlen.c
        printd.c
        struct_help.c
        test.c
        with_mod_help.c)

add_executable(ft_printf ${SOURCE_FILES})