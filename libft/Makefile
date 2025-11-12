NAME = libft.a
AR = ar
CC := cc
CFLAGS := -Wall -Werror -Wextra
ARFLAGS := rcs
SRC := ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_strlcpy.c \
ft_isalpha.c \
ft_strlen.c \
ft_isdigit.c \
ft_isascii.c \
ft_isprint.c \
ft_memcpy.c \
ft_memset.c \
ft_tolower.c \
ft_toupper.c \
ft_strchr.c \
ft_strrchr.c \
ft_strlcat.c \
ft_strncmp.c \

OBJFILES := $(SRC:.c=.o)

.PHONY: clean

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

