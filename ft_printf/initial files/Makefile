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
AR = ar
CC := cc
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := rcs

SRCS := ft_printf.c

OBJFILES := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJFILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean:
	rm -f $(NAME)

re: fclean all
