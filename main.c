#include "libft.h"

#include <string.h>
#include <ctype.h>
#include <stdio.h>

void isdigit_test(void)
{
	printf("\n=== Testing ft_isdigit ===\n");
	printf("Digits (expected return 1): \n");
	printf("'5' %d\n", ft_isdigit('5'));	
	printf("\n");

	printf("Letters (expected return 0):\n");
	printf("'a': %d\n", ft_isdigit('a'));
	printf("'Z': %d\n", ft_isdigit('Z'));
	printf("\n");
	
	printf("Boundary cases (should return 0):\n");
	printf("'/' (before '0'): %d\n", ft_isdigit('/'));  // ASCII 47
	printf("':' (after '9'): %d\n", ft_isdigit(':'));   // ASCII 58
	printf("\n");

    	printf("Special characters (should return 0):\n");
    	printf("\n");

	printf("Edge values:\n");
	printf("0 (null): %d\n", ft_isdigit(0));
	printf("-1: %d\n", ft_isdigit(-1));
	printf("127: %d\n", ft_isdigit(127));
	printf("200: %d\n", ft_isdigit(200));
}

int	main(void)
{
	printf("╔════════════════════════════════════════╗\n");
	printf("║     PENNY'S LIBFT FUNCTION TESTER      ║\n");
	printf("╚════════════════════════════════════════╝\n");

	isdigit_test();

	return (0);
}
