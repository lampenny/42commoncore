NAME = libft.a
AR = ar
CC := cc
CFLAGS := -Wall -Wextra -Werror
ARFLAGS := rcs

SRCS := ft_putchar_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c

OBJFILES := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJFILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

