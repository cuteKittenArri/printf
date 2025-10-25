# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stmuller <stmuller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 21:05:04 by stmuller          #+#    #+#              #
#    Updated: 2025/10/24 21:05:04 by stmuller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Werror -Wextra
CFILES := ft_printf.c ft_printf_functions.c ft_lib_functions.c ft_printf_ptr.c ft_printf_hex.c
OFILES := $(CFILES:.c=.o)
HEAD := ft_printf.h

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re