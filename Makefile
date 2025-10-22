
NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Werror -Wextra
CFILES := ft_printf.c ft_printf_functions.c ft_lib_functions.c
OFILES := $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re