*This project has been created as part of the 42 curriculum by penlam.*

# Description

Recode C's `printf()`, the prototype being:

`int    ft_printf(const char *, ...);`

The main difference is that my printf does not implement the buffer management of the original `printf()`. 

# Instructions

To compile run `make` in the terminal:

`$ make`

You should see an output like this:

```
$ make
cc -Wall -Wextra -Werror -c ft_printf.c -o ft_printf.o
cc -Wall -Wextra -Werror -c ft_puthex.c -o ft_puthex.o
ar rcs libftprintf.a ft_printf.o ft_putchar.o ft_putstr.o ft_putnbr.o ft_putuint.o ft_putptr.o ft_puthex.o
```

Then to run with your test file e.g. `main.c`:

`cc main.c libftprintf.a -o test`

# Resources

Think Like A Programmer by V. Anton Spraul

Code by Charles Petzold

https://www.geeksforgeeks.org/c/variadic-functions-in-c/

http://ld2015.scusa.lsu.edu/cppreference/en/cpp/utility/variadic/va_list.html#:~:text=If%20a%20va_list%20instance%20is,object%20after%20the%20function%20returns.

https://www.gnu.org/software/make/manual/make.html

https://www.cs.yale.edu/homes/aspnes/pinewiki/C%282f%29Pointers.html 

https://pythontutor.com/visualize.html

https://www.geeksforgeeks.org/c/c-pointers/

https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Printing-Pointers.html

#### How AI was used

AI was used to help me explain new concepts such as the point of hexadecimals and variadic functions and how va_list works. I also asked AI to check my code for errors or any gotchas that I might have overlooked.

### Explanation and justification of chosen implementation

I recreated a very simplified version of the standard C printf as per the subject instructions. It parses a format string, identifies format specifiers and outputs the corresponding args to standard output. The core logic of the function is inside `ft_printf.c` where it has the `ft_printf`, `handle_format` and `is_valid_format`. For the helper functions, I originally wanted to use my libft however, it would have meant a bit of refactoring which had the equivalent effort to rewriting `putchar`, `putstr` and `putnbr`.


