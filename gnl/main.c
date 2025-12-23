#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void test_stdin(void)
{
    char *line;

    printf("=== Testing stdin ===\n");
    printf("Type lines (Ctrl+D to stop):\n");
    while ((line = get_next_line(0)) != NULL)
    {
        printf("Got: [%s]\n", line);
        free(line);
    }
    printf("\n");
}

void test_file(void)
{
    int fd;
    char *line;
    int line_num;

    printf("=== Testing file ===\n");
    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Error opening file\n");
        return;
    }
    line_num = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: [%s]\n", line_num, line);
        free(line);
        line_num++;
    }
    close(fd);
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == 's')
        test_stdin();
    else if (argc == 2 && argv[1][0] == 'f')
        test_file();
    else
    {
        printf("Usage:\n");
        printf("  ./test_gnl s    (test stdin)\n");
        printf("  ./test_gnl f    (test file)\n");
    }
    return (0);
}