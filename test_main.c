#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

// Helper function to print memory in hex
void print_memory(void *ptr, size_t size)
{
    unsigned char *p = (unsigned char *)ptr;
    for (size_t i = 0; i < size; i++)
        printf("%02x ", p[i]);
    printf("\n");
}

// Helper to compare memory
int mem_compare(void *s1, void *s2, size_t n)
{
    return memcmp(s1, s2, n) == 0;
}

void test_strlen(void)
{
    printf("\n=== Testing ft_strlen ===\n");
    
    char *test1 = "hello";
    char *test2 = "";
    char *test3 = "this is a longer string";
    
    printf("ft_strlen(\"%s\") = %d, strlen = %d %s\n", 
        test1, ft_strlen(test1), strlen(test1),
        ft_strlen(test1) == strlen(test1) ? "✓" : "✗");
    
    printf("ft_strlen(\"%s\") = %d, strlen = %d %s\n", 
        test2, ft_strlen(test2), strlen(test2),
        ft_strlen(test2) == strlen(test2) ? "✓" : "✗");
    
    printf("ft_strlen(\"%s\") = %d, strlen = %d %s\n", 
        test3, ft_strlen(test3), strlen(test3),
        ft_strlen(test3) == strlen(test3) ? "✓" : "✗");
}

void test_strchr(void)
{
    printf("\n=== Testing ft_strchr ===\n");
    
    char *test = "hello world";
    
    printf("ft_strchr(\"%s\", 'o') = %s\n", test, ft_strchr(test, 'o'));
    printf("strchr(\"%s\", 'o') = %s %s\n", test, strchr(test, 'o'),
        ft_strchr(test, 'o') == strchr(test, 'o') ? "✓" : "✗");
    
    printf("ft_strchr(\"%s\", 'z') = %s\n", test, ft_strchr(test, 'z'));
    printf("strchr(\"%s\", 'z') = %s %s\n", test, strchr(test, 'z'),
        ft_strchr(test, 'z') == strchr(test, 'z') ? "✓" : "✗");
    
    // Test for null terminator
    printf("ft_strchr(\"%s\", '\\0') = %s\n", test, ft_strchr(test, '\0'));
    printf("strchr(\"%s\", '\\0') = %s %s\n", test, strchr(test, '\0'),
        ft_strchr(test, '\0') == strchr(test, '\0') ? "✓" : "✗");
}

void test_strrchr(void)
{
    printf("\n=== Testing ft_strrchr ===\n");
    
    char *test = "hello world";
    
    printf("ft_strrchr(\"%s\", 'l') = %s\n", test, ft_strrchr(test, 'l'));
    printf("strrchr(\"%s\", 'l') = %s %s\n", test, strrchr(test, 'l'),
        ft_strrchr(test, 'l') == strrchr(test, 'l') ? "✓" : "✗");
    
    printf("ft_strrchr(\"%s\", 'h') = %s\n", test, ft_strrchr(test, 'h'));
    printf("strrchr(\"%s\", 'h') = %s %s\n", test, strrchr(test, 'h'),
        ft_strrchr(test, 'h') == strrchr(test, 'h') ? "✓" : "✗");
    
    printf("ft_strrchr(\"%s\", 'z') = %s\n", test, ft_strrchr(test, 'z'));
    printf("strrchr(\"%s\", 'z') = %s %s\n", test, strrchr(test, 'z'),
        ft_strrchr(test, 'z') == strrchr(test, 'z') ? "✓" : "✗");
}

void test_strlcpy(void)
{
    printf("\n=== Testing ft_strlcpy ===\n");
    
    char src[] = "hello world";
    char dst1[20];
    char dst2[20];
    char dst3[5];
    char dst4[5];
    char dst5[15];
    char dst6[15];
    
    // Small buffer
    size_t ret1 = ft_strlcpy(dst3, src, sizeof(dst3));
    size_t ret2 = strlcpy(dst4, src, sizeof(dst4));
    printf("Small buffer (size 5):\n");
    printf("  ft_strlcpy: \"%s\" (ret=%zu)\n", dst3, ret1);
    printf("  strlcpy:    \"%s\" (ret=%zu) %s\n", dst4, ret2,
        (ret1 == ret2 && strcmp(dst3, dst4) == 0) ? "✓" : "✗");
    
    // Exact size
    size_t ret3 = ft_strlcpy(dst5, src, sizeof(dst5));
    size_t ret4 = strlcpy(dst6, src, sizeof(dst6));
    printf("Exact size (size 15):\n");
    printf("  ft_strlcpy: \"%s\" (ret=%zu)\n", dst5, ret3);
    printf("  strlcpy:    \"%s\" (ret=%zu) %s\n", dst6, ret4,
        (ret3 == ret4 && strcmp(dst5, dst6) == 0) ? "✓" : "✗");
    
    // Large buffer
    size_t ret5 = ft_strlcpy(dst1, src, sizeof(dst1));
    size_t ret6 = strlcpy(dst2, src, sizeof(dst2));
    printf("Large buffer (size 20):\n");
    printf("  ft_strlcpy: \"%s\" (ret=%zu)\n", dst1, ret5);
    printf("  strlcpy:    \"%s\" (ret=%zu) %s\n", dst2, ret6,
        (ret5 == ret6 && strcmp(dst1, dst2) == 0) ? "✓" : "✗");
}

void test_atoi(void)
{
    printf("\n=== Testing ft_atoi ===\n");
    
    char *test1 = "12345";
    char *test2 = "-678";
    char *test3 = "   42";
    char *test4 = "0";
    char *test5 = "   -123abc";
    char *test6 = "+987";
    char *test7 = "2147483647";  // INT_MAX
    char *test8 = "-2147483648"; // INT_MIN
    
    printf("ft_atoi(\"%s\") = %d, atoi = %d %s\n", 
        test1, ft_atoi(test1), atoi(test1),
        ft_atoi(test1) == atoi(test1) ? "✓" : "✗");
    
    printf("ft_atoi(\"%s\") = %d, atoi = %d %s\n", 
        test2, ft_atoi(test2), atoi(test2),
        ft_atoi(test2) == atoi(test2) ? "✓" : "✗");
    
    printf("ft_atoi(\"%s\") = %d, atoi = %d %s\n", 
        test3, ft_atoi(test3), atoi(test3),
        ft_atoi(test3) == atoi(test3) ? "✓" : "✗");
    
    printf("ft_atoi(\"%s\") = %d, atoi = %d %s\n", 
        test4, ft_atoi(test4), atoi(test4),
        ft_atoi(test4) == atoi(test4) ? "✓" : "✗");
    
    printf("ft_atoi(\"%s\") = %d, atoi = %d %s\n", 
        test5, ft_atoi(test5), atoi(test5),
        ft_atoi(test5) == atoi(test5) ? "✓" : "✗");
    
    printf("ft_atoi(\"%s\") = %d, atoi = %d %s\n", 
        test6, ft_atoi(test6), atoi(test6),
        ft_atoi(test6) == atoi(test6) ? "✓" : "✗");
    
    printf("ft_atoi(\"%s\") = %d, atoi = %d %s\n", 
        test7, ft_atoi(test7), atoi(test7),
        ft_atoi(test7) == atoi(test7) ? "✓" : "✗");
    
    printf("ft_atoi(\"%s\") = %d, atoi = %d %s\n", 
        test8, ft_atoi(test8), atoi(test8),
        ft_atoi(test8) == atoi(test8) ? "✓" : "✗");
}

void test_isalpha(void)
{
    printf("\n=== Testing ft_isalpha ===\n");
    
    int tests[] = {'a', 'Z', '5', ' ', '\n', 'M', '!', 0};
    
    for (int i = 0; tests[i] != 0; i++)
    {
        int c = tests[i];
        printf("ft_isalpha('%c') = %d, isalpha = %d %s\n",
            c, ft_isalpha(c), isalpha(c),
            (!!ft_isalpha(c) == !!isalpha(c)) ? "✓" : "✗");
    }
}

void test_isdigit(void)
{
    printf("\n=== Testing ft_isdigit ===\n");
    
    int tests[] = {'0', '9', '5', 'a', ' ', 'Z', -1, 128};
    
    for (int i = 0; i < 8; i++)
    {
        int c = tests[i];
        printf("ft_isdigit('%c'/%d) = %d, isdigit = %d %s\n",
            (c >= 32 && c <= 126) ? c : '?', c, 
            ft_isdigit(c), isdigit(c),
            (!!ft_isdigit(c) == !!isdigit(c)) ? "✓" : "✗");
    }
}

void test_isalnum(void)
{
    printf("\n=== Testing ft_isalnum ===\n");
    
    int tests[] = {'a', 'Z', '5', ' ', '!', 'M', '0'};
    
    for (int i = 0; i < 7; i++)
    {
        int c = tests[i];
        printf("ft_isalnum('%c') = %d, isalnum = %d %s\n",
            c, ft_isalnum(c), isalnum(c),
            (!!ft_isalnum(c) == !!isalnum(c)) ? "✓" : "✗");
    }
}

void test_isascii(void)
{
    printf("\n=== Testing ft_isascii ===\n");
    
    int tests[] = {0, 'a', 127, 128, -1, 'Z', 255};
    
    for (int i = 0; i < 7; i++)
    {
        int c = tests[i];
        printf("ft_isascii(%d) = %d, isascii = %d %s\n",
            c, ft_isascii(c), isascii(c),
            (!!ft_isascii(c) == !!isascii(c)) ? "✓" : "✗");
    }
}

void test_isprint(void)
{
    printf("\n=== Testing ft_isprint ===\n");
    
    int tests[] = {' ', '~', 'a', '\n', '\t', 31, 32, 126, 127};
    
    for (int i = 0; i < 9; i++)
    {
        int c = tests[i];
        printf("ft_isprint(%d/'%c') = %d, isprint = %d %s\n",
            c, (c >= 32 && c <= 126) ? c : '?',
            ft_isprint(c), isprint(c),
            (!!ft_isprint(c) == !!isprint(c)) ? "✓" : "✗");
    }
}

void test_toupper(void)
{
    printf("\n=== Testing ft_toupper ===\n");
    
    int tests[] = {'a', 'z', 'A', 'Z', '5', ' ', 'm'};
    
    for (int i = 0; i < 7; i++)
    {
        int c = tests[i];
        printf("ft_toupper('%c') = '%c', toupper = '%c' %s\n",
            c, ft_toupper(c), toupper(c),
            (ft_toupper(c) == toupper(c)) ? "✓" : "✗");
    }
}

void test_tolower(void)
{
    printf("\n=== Testing ft_tolower ===\n");
    
    int tests[] = {'A', 'Z', 'a', 'z', '5', ' ', 'M'};
    
    for (int i = 0; i < 7; i++)
    {
        int c = tests[i];
        printf("ft_tolower('%c') = '%c', tolower = '%c' %s\n",
            c, ft_tolower(c), tolower(c),
            (ft_tolower(c) == tolower(c)) ? "✓" : "✗");
    }
}

void test_memset(void)
{
    printf("\n=== Testing ft_memset ===\n");
    
    char buf1[20];
    char buf2[20];
    
    // Test 1: Fill with 'A'
    ft_memset(buf1, 'A', 10);
    memset(buf2, 'A', 10);
    printf("memset 10 bytes with 'A': %s\n", 
        mem_compare(buf1, buf2, 10) ? "✓" : "✗");
    printf("  ft_memset: ");
    print_memory(buf1, 10);
    printf("  memset:    ");
    print_memory(buf2, 10);
    
    // Test 2: Fill with 0
    ft_memset(buf1, 0, 5);
    memset(buf2, 0, 5);
    printf("memset 5 bytes with 0: %s\n", 
        mem_compare(buf1, buf2, 5) ? "✓" : "✗");
    
    // Test 3: Fill entire buffer
    ft_memset(buf1, 'X', sizeof(buf1));
    memset(buf2, 'X', sizeof(buf2));
    printf("memset entire buffer (20 bytes) with 'X': %s\n", 
        mem_compare(buf1, buf2, sizeof(buf1)) ? "✓" : "✗");
}

void test_bzero(void)
{
    printf("\n=== Testing ft_bzero ===\n");
    
    char buf1[20];
    char buf2[20];
    
    // Fill with data first
    memset(buf1, 'A', sizeof(buf1));
    memset(buf2, 'A', sizeof(buf2));
    
    // Test 1: Zero 5 bytes
    ft_bzero(buf1, 5);
    bzero(buf2, 5);
    printf("bzero 5 bytes: %s\n", 
        mem_compare(buf1, buf2, sizeof(buf1)) ? "✓" : "✗");
    printf("  ft_bzero: ");
    print_memory(buf1, 10);
    printf("  bzero:    ");
    print_memory(buf2, 10);
    
    // Test 2: Zero entire buffer
    memset(buf1, 'B', sizeof(buf1));
    memset(buf2, 'B', sizeof(buf2));
    ft_bzero(buf1, sizeof(buf1));
    bzero(buf2, sizeof(buf2));
    printf("bzero entire buffer (20 bytes): %s\n", 
        mem_compare(buf1, buf2, sizeof(buf1)) ? "✓" : "✗");
    
    // Test 3: Zero 0 bytes (should do nothing)
    memset(buf1, 'C', sizeof(buf1));
    memset(buf2, 'C', sizeof(buf2));
    ft_bzero(buf1, 0);
    bzero(buf2, 0);
    printf("bzero 0 bytes: %s\n", 
        mem_compare(buf1, buf2, sizeof(buf1)) ? "✓" : "✗");
}

void test_memcpy(void)
{
    printf("\n=== Testing ft_memcpy ===\n");
    
    char src[] = "Hello, World!";
    char dst1[20];
    char dst2[20];
    
    // Test 1: Copy 5 bytes
    ft_memcpy(dst1, src, 5);
    memcpy(dst2, src, 5);
    printf("memcpy 5 bytes: %s\n", 
        mem_compare(dst1, dst2, 5) ? "✓" : "✗");
    printf("  ft_memcpy: ");
    print_memory(dst1, 5);
    printf("  memcpy:    ");
    print_memory(dst2, 5);
    
    // Test 2: Copy entire string
    ft_memcpy(dst1, src, strlen(src) + 1);
    memcpy(dst2, src, strlen(src) + 1);
    printf("memcpy entire string: %s\n", 
        mem_compare(dst1, dst2, strlen(src) + 1) ? "✓" : "✗");
    printf("  ft_memcpy: \"%s\"\n", dst1);
    printf("  memcpy:    \"%s\"\n", dst2);
    
    // Test 3: Copy 0 bytes
    memset(dst1, 'X', sizeof(dst1));
    memset(dst2, 'X', sizeof(dst2));
    ft_memcpy(dst1, src, 0);
    memcpy(dst2, src, 0);
    printf("memcpy 0 bytes: %s\n", 
        mem_compare(dst1, dst2, sizeof(dst1)) ? "✓" : "✗");
}

int main(void)
{
    printf("╔════════════════════════════════════════╗\n");
    printf("║     LIBFT FUNCTION TESTER v1.0         ║\n");
    printf("╚════════════════════════════════════════╝\n");
    
    test_strlen();
    test_strchr();
    test_strrchr();
    test_strlcpy();
    test_atoi();
    test_isalpha();
    test_isdigit();
    test_isalnum();
    test_isascii();
    test_isprint();
    test_toupper();
    test_tolower();
    test_memset();
    test_bzero();
    test_memcpy();
    
    printf("\n╔════════════════════════════════════════╗\n");
    printf("║          TESTING COMPLETE!             ║\n");
    printf("╚════════════════════════════════════════╝\n");
    
    return (0);
}
