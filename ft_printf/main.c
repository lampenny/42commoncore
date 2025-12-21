#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	c = 'X';
	char	s[] = "abcdefghijklmnopqrstuvwxyz";
	int		i = 425;
	short int	j = 17;
	unsigned int	u = 0xf179U;
	char	str[] = "===this is my string";
	char	str1[] = "===this is my other string";
	printf("\n Characters: \n");
	ft_printf("my printf - char: %c\n", 'A');
	ft_printf("%c\n", c);
	ft_printf("%3c%3c\n", c, c);
	ft_printf("%x\n", c);
	printf("\n Strings \n");
	ft_printf("%s\n", s);
	ft_printf("my printf - str: %s testing multiple args: %s\n", str, str1);
	ft_printf("\n Integers \n");
	ft_printf("%i %o %x %u\n", i, i, i, i);
	printf("sys hex -low -up: %x %X \n", 255, 255);
	ft_printf("my hex - low -up: %x %X \n", 255, 255);
	printf("sys printf: %p \n", NULL);
	ft_printf("my printf: %p \n", NULL);
	return (0);
}
