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
	{
		printf("PASSED \n");
		printf("RESULT: %s \n", result);
	}
	else
	{
		printf("FAILED \n");
		printf("Expected: %s \n", expected);
		printf(" Received: %s \n", result);
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
void toupper_test()
{
	printf("\n====== Testing ft_toupper ======\n");
	int a;
	a = 'a';
	printf("lowercase a: %c \n", ft_toupper(a));
}

void tolower_test()
{
	printf("\n====== Testing ft_tolower ======\n");
	int a;
	int b;
	a = 'A';
	b = 'b';
	printf("uppercase A: %c \n", ft_tolower(a));
	printf("lowercase b: %c \n", ft_tolower(b));
}
void memcpy_test()
{
	printf("\n====== Testing ft_memcpy ======\n");
	int passed = 0;
	int total = 0;

	// Test 1: Basic string copy
	{
		char source[20] = "Hello";
		char dest[20] = {0}; // Initialize to zero
		total++;

		ft_memcpy(dest, source, 6); // Copy including null terminator
		if (strcmp(dest, "Hello") == 0)
		{
			printf("✓ Test 1 PASSED: Basic string copy\n");
			passed++;
		}
		else
		{
			printf("✗ Test 1 FAILED: Expected 'Hello', got '%s'\n", dest);
		}
	}

	// Test 2: Partial copy
	{
		char source[] = "Hello World";
		char dest[20] = {0};
		total++;

		ft_memcpy(dest, source, 5); // Copy only "Hello"
		dest[5] = '\0';				// Manually null-terminate
		if (strcmp(dest, "Hello") == 0)
		{
			printf("✓ Test 2 PASSED: Partial copy\n");
			passed++;
		}
		else
		{
			printf("✗ Test 2 FAILED: Expected 'Hello', got '%s'\n", dest);
		}
	}

	// Test 3: Copy with binary data (including null bytes)
	{
		unsigned char source[] = {1, 2, 0, 3, 4};
		unsigned char dest[5] = {0};
		total++;

		ft_memcpy(dest, source, 5);
		if (memcmp(dest, source, 5) == 0)
		{
			printf("✓ Test 3 PASSED: Binary data with null bytes\n");
			passed++;
		}
		else
		{
			printf("✗ Test 3 FAILED: Binary data mismatch\n");
		}
	}

	// Test 4: Copy integers
	{
		int source[] = {1, 2, 3, 4, 5};
		int dest[5] = {0};
		total++;

		ft_memcpy(dest, source, sizeof(source));
		if (memcmp(dest, source, sizeof(source)) == 0)
		{
			printf("✓ Test 4 PASSED: Integer array copy\n");
			passed++;
		}
		else
		{
			printf("✗ Test 4 FAILED: Integer array mismatch\n");
		}
	}

	// Test 5: Zero-length copy
	{
		char source[] = "Hello";
		char dest[] = "World";
		total++;

		ft_memcpy(dest, source, 0);
		if (strcmp(dest, "World") == 0)
		{ // dest should be unchanged
			printf("✓ Test 5 PASSED: Zero-length copy\n");
			passed++;
		}
		else
		{
			printf("✗ Test 5 FAILED: Destination was modified\n");
		}
	}

	// Test 6: Compare with standard memcpy
	{
		char source[] = "Test string for comparison";
		char dest1[50] = {0};
		char dest2[50] = {0};
		total++;

		memcpy(dest1, source, sizeof(source));
		ft_memcpy(dest2, source, sizeof(source));

		if (memcmp(dest1, dest2, sizeof(source)) == 0)
		{
			printf("✓ Test 6 PASSED: Matches standard memcpy behavior\n");
			passed++;
		}
		else
		{
			printf("✗ Test 6 FAILED: Does not match standard memcpy\n");
		}
	}

	// Summary
	printf("\n--- Summary: %d/%d tests passed ---\n", passed, total);
	if (passed == total)
	{
		printf("All tests PASSED! ✓\n");
	}
	else
	{
		printf("Some tests FAILED ✗\n");
	}
}

void strjoin_test()
{
	printf("\n====== Testing ft_strjoin ======\n");
	int passed = 0;
	int total = 0;
	char *result;

	// Test 1: Basic string concatenation
	{
		total++;
		result = ft_strjoin("Hello", " World");
		if (result && strcmp(result, "Hello World") == 0)
		{
			printf("✓ Test 1 PASSED: Basic concatenation\n");
			passed++;
		}
		else
		{
			printf("✗ Test 1 FAILED: Expected 'Hello World', got '%s'\n",
				   result ? result : "NULL");
		}
		free(result);
	}

	// Test 2: Empty first string
	{
		total++;
		result = ft_strjoin("", "World");
		if (result && strcmp(result, "World") == 0)
		{
			printf("✓ Test 2 PASSED: Empty first string\n");
			passed++;
		}
		else
		{
			printf("✗ Test 2 FAILED: Expected 'World', got '%s'\n",
				   result ? result : "NULL");
		}
		free(result);
	}

	// Test 3: Empty second string
	{
		total++;
		result = ft_strjoin("Hello", "");
		if (result && strcmp(result, "Hello") == 0)
		{
			printf("✓ Test 3 PASSED: Empty second string\n");
			passed++;
		}
		else
		{
			printf("✗ Test 3 FAILED: Expected 'Hello', got '%s'\n",
				   result ? result : "NULL");
		}
		free(result);
	}

	// Test 4: Both strings empty
	{
		total++;
		result = ft_strjoin("", "");
		if (result && strcmp(result, "") == 0)
		{
			printf("✓ Test 4 PASSED: Both strings empty\n");
			passed++;
		}
		else
		{
			printf("✗ Test 4 FAILED: Expected '', got '%s'\n",
				   result ? result : "NULL");
		}
		free(result);
	}

	// Test 5: Long strings
	{
		total++;
		char *long1 = "This is a very long string that should be concatenated";
		char *long2 = " with another long string to test memory allocation";
		char *expected = "This is a very long string that should be concatenated"
						 " with another long string to test memory allocation";
		result = ft_strjoin(long1, long2);
		if (result && strcmp(result, expected) == 0)
		{
			printf("✓ Test 5 PASSED: Long strings\n");
			passed++;
		}
		else
		{
			printf("✗ Test 5 FAILED: Long string concatenation failed\n");
		}
		free(result);
	}

	// Test 6: Single character strings
	{
		total++;
		result = ft_strjoin("A", "B");
		if (result && strcmp(result, "AB") == 0)
		{
			printf("✓ Test 6 PASSED: Single character strings\n");
			passed++;
		}
		else
		{
			printf("✗ Test 6 FAILED: Expected 'AB', got '%s'\n",
				   result ? result : "NULL");
		}
		free(result);
	}

	// Test 7: Strings with special characters
	{
		total++;
		result = ft_strjoin("Hello\n", "\tWorld!");
		if (result && strcmp(result, "Hello\n\tWorld!") == 0)
		{
			printf("✓ Test 7 PASSED: Special characters\n");
			passed++;
		}
		else
		{
			printf("✗ Test 7 FAILED: Special characters not handled correctly\n");
		}
		free(result);
	}

	// Test 8: Strings with numbers
	{
		total++;
		result = ft_strjoin("42", "24");
		if (result && strcmp(result, "4224") == 0)
		{
			printf("✓ Test 8 PASSED: Numeric strings\n");
			passed++;
		}
		else
		{
			printf("✗ Test 8 FAILED: Expected '4224', got '%s'\n",
				   result ? result : "NULL");
		}
		free(result);
	}

	// Test 9: Memory allocation check (result is unique)
	{
		total++;
		char *s1 = "Hello";
		char *s2 = "World";
		result = ft_strjoin(s1, s2);
		// Verify result is a new allocation (not pointing to s1 or s2)
		if (result && result != s1 && result != s2)
		{
			printf("✓ Test 9 PASSED: Returns new allocated memory\n");
			passed++;
		}
		else
		{
			printf("✗ Test 9 FAILED: Should return new allocation\n");
		}
		free(result);
	}

	// Test 10: Null termination check
	{
		total++;
		result = ft_strjoin("Test", "123");
		if (result && result[7] == '\0' && strlen(result) == 7)
		{
			printf("✓ Test 10 PASSED: Proper null termination\n");
			passed++;
		}
		else
		{
			printf("✗ Test 10 FAILED: String not properly null-terminated\n");
		}
		free(result);
	}

	// Test 11: Strings with spaces
	{
		total++;
		result = ft_strjoin("Hello   ", "   World");
		if (result && strcmp(result, "Hello      World") == 0)
		{
			printf("✓ Test 11 PASSED: Multiple spaces preserved\n");
			passed++;
		}
		else
		{
			printf("✗ Test 11 FAILED: Spaces not handled correctly\n");
		}
		free(result);
	}

	// Test 12: Compare length calculation
	{
		total++;
		char *s1 = "First";
		char *s2 = "Second";
		result = ft_strjoin(s1, s2);
		size_t expected_len = strlen(s1) + strlen(s2);
		if (result && strlen(result) == expected_len)
		{
			printf("✓ Test 12 PASSED: Correct length calculation\n");
			passed++;
		}
		else
		{
			printf("✗ Test 12 FAILED: Length is %zu, expected %zu\n",
				   result ? strlen(result) : 0, expected_len);
		}
		free(result);
	}

	// Summary
	printf("\n--- Summary: %d/%d tests passed ---\n", passed, total);
	if (passed == total)
	{
		printf("All tests PASSED! ✓\n");
	}
	else
	{
		printf("Some tests FAILED ✗\n");
	}
}

void strtrim_test()
{
	printf("\n====== Testing ft_strtrim ======\n");
	char *test_string = "aaabbbHELLOaaabbb";
	char *set = "ab";
	char *result;

	result = ft_strtrim(test_string, set);
	print_test_str(result, "HELLO");

	test_string = "hihihihiMy Name is Pennyhihihihihi";
	set = "hi";
	result = ft_strtrim(test_string, set);
	print_test_str(result, "My Name is Penny");
}
void print_result_split(char **result)
{
	int i = 0;

	if (!result)
	{
		printf("Result is NULL\n");
		return;
	}

	printf("[\n");
	while (result[i])
	{
		printf("  [%d]: \"%s\"\n", i, result[i]);
		i++;
	}
	printf("]\n");
	printf("Total words: %d\n\n", i);
}

void free_result(char **result)
{
	int i = 0;

	if (!result)
		return;

	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void split_test(void)
{
	char **result;
	printf("\n====== Testing ft_split ======\n");
	printf("=== TEST 1: Basic split ===\n");
	result = ft_split("hello world test", ' ');
	print_result_split(result);
	free_result(result);

	printf("=== TEST 2: Multiple delimiters ===\n");
	result = ft_split("..My name..is..Penny", '.');
	print_result_split(result);
	free_result(result);

	printf("=== TEST 3: Leading delimiters ===\n");
	result = ft_split("   hello world", ' ');
	print_result_split(result);
	free_result(result);

	printf("=== TEST 4: Trailing delimiters ===\n");
	result = ft_split("hello world   ", ' ');
	print_result_split(result);
	free_result(result);

	printf("=== TEST 5: Only delimiters ===\n");
	result = ft_split(".....", '.');
	print_result_split(result);
	free_result(result);

	printf("=== TEST 6: No delimiters ===\n");
	result = ft_split("hello", ' ');
	print_result_split(result);
	free_result(result);

	printf("=== TEST 7: Empty string ===\n");
	result = ft_split("", ' ');
	print_result_split(result);
	free_result(result);

	printf("=== TEST 8: Single character ===\n");
	result = ft_split("a", ' ');
	print_result_split(result);
	free_result(result);

	printf("=== TEST 9: NULL string ===\n");
	result = ft_split(NULL, ' ');
	print_result_split(result);
	free_result(result);

	printf("=== TEST 10: Complex case ===\n");
	result = ft_split("one,,two,,,three,,,,four", ',');
	print_result_split(result);
	free_result(result);

	printf("All tests completed!\n");
}

void memcmp_test()
{
	char s1[] = "hello";
	char s2[] = "hello";
	char s3[] = "hellx";

	printf("\n====== Testing ft_memcmp ======\n");

	printf("equal: %d\n", ft_memcmp(s1, s2, 5));
	printf("should be 0\n");

	// Test different strings
	printf("diff: %d\n", ft_memcmp(s1, s3, 5));
	printf("should be negative (o < x)\n");

	// Test with n = 0
	printf("n=0: %d\n", ft_memcmp(s1, s3, 0));
	printf("should be 0\n");

	// Test partial compare
	printf("partial: %d\n", ft_memcmp(s1, s3, 4));
	printf("should be 0 (first 4 match)\n");
}

void memmove_test()
{
	printf("\n====== Testing ft_memmove ======\n");
	// Test 1: simple copy
	char s1[] = "hello";
	char s2[10];
	ft_memmove(s2, s1, 6);
	printf("simple: %s\n", s2); // should print "hello"

	// Test 2: overlapping memory
	char s3[] = "hello";
	ft_memmove(s3 + 1, s3, 4);
	printf("overlap: %s\n", s3); // should print "hhell"
}

void memset_test()
{
	printf("\n====== Testing ft_memset ======\n");
	char str[50] = "Penny penny penny penny penny penny";
	printf("before ft_memset() %s\n", str);

	// Fill 6 characters starting from str[11] with '*'
	printf("call ft_memset and fill 6 characters starting from str[11] with '*' \n");
	ft_memset(str + 11, '*', 6);

	printf("after ft_memset() %s \n", str);
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
	toupper_test();
	tolower_test();
	memcpy_test();
	atoi_test();
	bzero_test();
	calloc_test();

	itoa_test();
	strjoin_test();
	strtrim_test();
	split_test();

	memcmp_test();
	memmove_test();
	memset_test();

	// striteri_test();

	// NOT YET IMPLEMENTED
	// substr_test();
	// strrchr_test();
	// strnstr_test();
	// strncmp_test();
	// strlen_test();
	// strlcpy_test();
	// strlcat_test();
	// striteri_test();
	// strdup_test();
	// strchr_test();

	// putstr_fd_test();
	// putnbr_fd_test();
	// putendl_fd_test();
	// putchar_ft_test();

	printf("\n╔════════════════════════════════════════╗\n");
	printf("║          TESTING COMPLETE!             ║\n");
	printf("╚════════════════════════════════════════╝\n");
	return (0);
}
