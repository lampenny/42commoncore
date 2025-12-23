#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
// 	char	c = 'X';
// 	char	s[] = "abcdefghijklmnopqrstuvwxyz";
// 	int		i = 425;
// //short int	j = 17;
// 	unsigned int	u = 0xf179U; // 61817
// 	unsigned int	u1 = 42424242;
// 	char	str[] = "===this is my string";
// 	char	str1[] = "==this is my other string";

// 	ft_printf("does not handle this format: %lu \n", 123456UL);
// 	ft_printf("Single percent sign %\n");

// 	printf("\n Characters: \n");
// 	ft_printf("my printf - char: %c\n", 'A');
// 	printf("sys printf - char: %c\n", 'A');
// 	ft_printf("my printf - char: %c\n", 'z');
// 	printf("sys printf - char: %c\n", 'z');
// 	ft_printf("my printf - char: %c\n", 1);
// 	printf("sys printf - char: %c\n", 1);
// 	ft_printf("my printf - char: %c\n", c);
// 	printf("sys printf - char: %c\n", c);

// 	printf("\n Strings \n");
// 	ft_printf("my printf, string: %s\n", s);
// 	printf("sys printf, string: %s\n", s);
// 	ft_printf("my printf - str: %s testing multiple args: %s\n", str, str1);
// 	printf("my printf - str: %s testing multiple args: %s\n", str, str1);


// 	ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 \n");
// 	printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 \n");

// 	ft_printf("\n Integers \n");
// 	ft_printf("mine, i, u: %i\n %d\n", i, i);
// 	printf("sys. i, u: %i\n %d\n", i, i);
// 	ft_printf("m, unsigned int (hex): %u \n", u);
// 	printf("s, unsigned int (hex): %u \n", u);
// 	ft_printf("m, unsigned int: %u \n", u1);
// 	printf("s, unsigned int: %u \n", u1);
// 	ft_printf("mine, negative uint: %u\n", -1);
// 	printf("sys, negative uint: %u\n", -1);

// 	ft_printf("\n Hexadecimals \n");
// 	ft_printf("my hex 255 -low -up: %x %X \n", 255, 255);
// 	printf("sys hex 255 -low -up: %x %X \n", 255, 255);
// 	ft_printf("my hex 51,966 -low -up: %x %X \n", 51966, 51966);
// 	printf("sys hex 51,966 -low -up: %x %X \n", 51966, 51966);

// 	ft_printf("\n Pointers \n");
// 	int n = 42;
// 	int *my_ptr;
// 	my_ptr = &n;
// 	printf("sys printf, pointer address %p \n", &my_ptr);
// 	ft_printf("my printf, pointer address %p \n", &my_ptr);
// 	ft_printf("memory address of n is %p \n", &n);
// 	printf("sys: memory address of n is %p \n", &n);
// 	printf("sys printf, null pointer: %p \n", NULL);
// 	ft_printf("my printf, null pointer: %p \n", NULL);

	printf(" %p %p ", (void *)0, (void *)0);
	printf("/n");
	ft_printf(" %p %p ", (void *)0, (void *)0);
	printf("/n");

	// printf("sys printf, long max: %p \n", (void *)LONG_MAX);
	// ft_printf("my printf, long max: %p \n", (void *)LONG_MAX);

	// printf("sys printf, long min: %p \n", (void *)LONG_MIN);
	// ft_printf("my printf, long min: %p \n", (void *)LONG_MIN);
	// ft_printf("\n Special case \n");
	// ft_printf("percent sign: %%\n");
	// printf("percent sign: %%\n");

	return (0);
}
