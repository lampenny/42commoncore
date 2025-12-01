#include <stdio.h>

int main()
{
	char	c = 'X';
	char	s[] = "abcdefghijklmnopqrstuvwxyz";
	int	i = 425;
	short int	j = 17;
	unsigned int	u = 0xf179U;

	printf("\n Integers \n");
	printf("%i %o %x %u\n", i, i, i, i);
	// i - decimal
	// o - octal
	// x - hexadecimal
	// u - unsigned

	printf("\n Characters: \n");
	printf("%c\n", c);
	printf("%3c%3c\n", c, c);
	printf("%x\n", c);

	printf("\n Strings \n");
	printf("%s\n", s);
	printf("%.5s\n", s);
	printf("%30s\n", s);
	printf("%20.5s\n", s);
	printf("%-20.5s\n", s);
	
	return 0;
}
