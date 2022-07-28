# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmilan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/23 14:20:37 by nmilan            #+#    #+#              #
#    Updated: 2022/07/24 21:48:21 by lcrimet          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

PROG = bloc_select.c ft_check_dict.c  ft_print_bloc.c ft_print_hundred.c ft_print_units.c ft_utilites.c main.c ft_print.c ft_print_zero.c

INCLUDE = ft.h

all : rush_02

clean :
	rm -f $(NAME)

fclean : clean

rush_02 : $(PROG) $(INCLUDE)
	gcc -Wall -Wextra -Werror -o $(NAME) $(PROG)


