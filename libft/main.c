#include "libft.h"

#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>

void print_test(int result, int expected)
{
	printf("%s\n", result == expected ? "PASSED" : "FAILED");
}

void print_test_str(char *result, const char *expected)
{
	int passed = (result != NULL && strcmp(result, expected) == 0);
	if (passed)
		printf("PASSED \n");
	else
	{
		printf("FAILED \n");
		printf("Expected: %s \n", expected);
		printf(" Received: %s \n", expected);
	}
	printf("\n");

	if (result)
		free(result);
}

void isupper_test(void)
{
	printf("\n====== Testing ft_toupper ======\n");
	int a;
	a = 'a';
	printf("Lowercase 'a': ");
	print_test(ft_toupper(a), 'A');
}

void isdigit_test(void)
{
	printf("\n====== Testing ft_isdigit ======\n");
	printf("Digits (expected return 1): \n");
	printf("'5' %d ", ft_isdigit('5'));
	print_test(ft_isdigit('5') != 0, 1);
	printf("\n");
	printf("Letters (expected return 0):\n");
	printf("'a': %d ", ft_isdigit('a'));
	print_test(ft_isdigit('a'), 0);
	printf("'Z': %d ", ft_isdigit('Z'));
	print_test(ft_isdigit('Z'), 0);
	printf("\n");
	printf("Boundary cases (should return 0):\n");
	printf("'/' (before '0'): %d ", ft_isdigit('/'));
	print_test(ft_isdigit('/'), 0);
	printf("':' (after '9'): %d ", ft_isdigit(':'));
	print_test(ft_isdigit(':'), 0);
	printf("\n");
	printf("Edge values:\n");
	printf("0 (null): %d ", ft_isdigit(0));
	print_test(ft_isdigit(0), 0);
	printf("-1: %d ", ft_isdigit(-1));
	print_test(ft_isdigit(-1), 0);
	printf("127: %d ", ft_isdigit(127));
	print_test(ft_isdigit(127), 0);
	printf("200: %d ", ft_isdigit(200));
	print_test(ft_isdigit(200), 0);
}

void atoi_test(void)
{
	printf("\n====== Testing ft_atoi ======\n");
	int val;

	val = ft_atoi("1509.10E");
	printf("val = %d (expected: 1509) ", val);
	print_test(val, 1509);

	val = ft_atoi("-9885");
	printf("val = %d (expected: -9885) ", val);
	print_test(val, -9885);

	val = ft_atoi("       -1234ab567");
	printf("val = %d (expected: -1234) ", val);
	print_test(val, -1234);
}

void bzero_test()
{
	printf("\n====== Testing ft_bzero ======\n");
	char test_arr[10] = "HELLOHELLO";
	size_t length = 10;

	printf("initial state: %s\n", test_arr);

	size_t bytes_to_clear = 5;
	printf("clearing bytes %zu", bytes_to_clear);

	ft_bzero(test_arr, bytes_to_clear);

	// loop and check byte by byte as part of the array is zeroed
	for (size_t i = 0; i < length; i++)
	{
		// Check if the byte is 0 (cleared) or still the original letter.
		if (test_arr[i] == 0)
			printf(" %zu    | 0 (CLEARED)\n", i);
		else
			printf(" %zu    | %c (STILL PRESENT)\n", i, test_arr[i]);
	}

	if (test_arr[0] == 0 && test_arr[4] == 0 && test_arr[5] == 'H')
		printf("\nTEST RESULT: PASS!\n");
	else
		printf("\nTEST RESULT: FAIL! (Memory was not cleared correctly.)\n");
}

void calloc_test()
{
	char *ptr;
	size_t len;
	printf("\n====== Testing ft_calloc ======\n");
	len = 50;
	ptr = (char *)ft_calloc(len, sizeof(char));

	if (ptr == NULL)
	{
		printf("Could not allocate memory");
		exit(1);
	}
	ft_strlcpy(ptr, "Penny learns C", len);
	printf("%s\n", ptr);
	free(ptr);

	ptr = (char *)ft_calloc(SIZE_MAX, SIZE_MAX);
	if (ptr == NULL)
	{
		printf("Overflow correctly detected (returned NULL)\n");
		printf("\nTEST RESULT: PASS!\n");
	}
	else
	{
		printf("ERROR: ft_calloc should have returned NULL!\n");
		free(ptr);
	}
}

void isalnum_test(void)
{
	printf("\n====== Testing ft_isalnum ======\n");
	printf("Letter 'a': ");
	print_test(ft_isalnum('a') != 0, 1);
	printf("Digit '5': ");
	print_test(ft_isalnum('5') != 0, 1);
	printf("Space ' ': ");
	print_test(ft_isalnum(' '), 0);
	printf("Symbol '@': ");
	print_test(ft_isalnum('@'), 0);
}

void isalpha_test(void)
{
	printf("\n====== Testing ft_isalpha ======\n");
	printf("Uppercase 'A': ");
	print_test(ft_isalpha('A') != 0, 1);
	printf("Lowercase 'z': ");
	print_test(ft_isalpha('z') != 0, 1);
	printf("Digit '5': ");
	print_test(ft_isalpha('5'), 0);
	printf("Symbol '!': ");
	print_test(ft_isalpha('!'), 0);
}

void isascii_test(void)
{
	printf("\n====== Testing ft_isascii ======\n");
	printf("Character 'A': ");
	print_test(ft_isascii('A') != 0, 1);
	printf("Value 0: ");
	print_test(ft_isascii(0) != 0, 1);
	printf("Value 127: ");
	print_test(ft_isascii(127) != 0, 1);
	printf("Value 128: ");
	print_test(ft_isascii(128), 0);
	printf("Value -1: ");
	print_test(ft_isascii(-1), 0);
}

void isprint_test(void)
{
	printf("\n====== Testing ft_isprint ======\n");
	printf("Space ' ': ");
	print_test(ft_isprint(' ') != 0, 1);
	printf("Letter 'A': ");
	print_test(ft_isprint('A') != 0, 1);
	printf("Tilde '~': ");
	print_test(ft_isprint('~') != 0, 1);
	printf("Tab '\\t': ");
	print_test(ft_isprint('\t'), 0);
	printf("Newline '\\n': ");
	print_test(ft_isprint('\n'), 0);
	printf("DEL (127): ");
	print_test(ft_isprint(127), 0);
}

void itoa_test()
{
	char *result;
	printf("\n====== Testing ft_itoa ======\n");
	// Test 1: zero
	printf("Zero: ");
	result = ft_itoa(0);
	print_test_str(result, "0");
	// Test 2: Positive number
	printf("Positive number: ");
	result = ft_itoa(42);
	print_test_str(result, "42");

	// Test 3: Negative number
	printf("Negative number: ");
	result = ft_itoa(-42);
	print_test_str(result, "-42");

	// Test 4: INT_MAX
	printf("INT_MAX: ");
	result = ft_itoa(INT_MAX);
	print_test_str(result, "2147483647");

	// Test 5: INT_MIN
	printf("INT_MIN: ");
	result = ft_itoa(INT_MIN);
	print_test_str(result, "-2147483648");
}

int main(void)
{
	printf("╔════════════════════════════════════════╗\n");
	printf("║     PENNY'S LIBFT FUNCTION TESTER      ║\n");
	printf("╚════════════════════════════════════════╝\n");

	isupper_test();
	isdigit_test();
	isprint_test();
	isascii_test();
	isalpha_test();
	isalnum_test();
	atoi_test();
	bzero_test();
	calloc_test();
	itoa_test();

	printf("\n╔════════════════════════════════════════╗\n");
	printf("║          TESTING COMPLETE!             ║\n");
	printf("╚════════════════════════════════════════╝\n");
	return (0);
}
