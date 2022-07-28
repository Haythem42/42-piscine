# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: habelhad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 13:07:08 by habelhad          #+#    #+#              #
#    Updated: 2022/07/28 17:27:28 by habelhad         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

PROG = ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c
	
INCLUDE = ./includes/ft.h

all : $(NAME)

clean :
	rm -f $(PROG)
	rm -f ./srcs/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all

$(NAME) : $(PROG) $(INCLUDE)
	gcc -Wall -Wextra -Werror -c $(PROG)
	mv *.o srcs/
	ar crs $(NAME) srcs/*.o
