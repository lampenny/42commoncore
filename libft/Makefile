NAME = libft.a
AR = ar

CC := cc
CFLAGS := -Wall -Werror -Wextra
ARFLAGS := rcs
SRC := ft_strlcpy.c ft_strlen.c ft_isalpha.c ft_strlen.c ft_isdigit.c
OBJFILES := $(SRC:.c=.o)

.PHONY: clean

all: $(NAME)

$(NAME): $(OBJFILES)
	$(AR) $(ARFLAGS) $(NAME) $(OBJFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(OBJFILES)

re: fclean all

