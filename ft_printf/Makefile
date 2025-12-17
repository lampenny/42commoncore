# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: penlam <penlam@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/30 17:53:18 by penlam            #+#    #+#              #
#    Updated: 2025/11/30 18:56:55 by penlam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_NAME = libft.a
LIBFT_DIR = ./libft
AR = ar
CC := cc
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := rcs

SRCS := ft_printf.c \
ft_putchar.c \
ft_putstr.c \
ft_putint.c

OBJFILES := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): makelibft $(OBJFILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJFILES)

makelibft:
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re makelibft