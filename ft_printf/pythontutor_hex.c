#include <stdio.h>
#include <stdarg.h>

int   ft_putchar(char c)
{
    return (write(1, &c, 1));
}


int ft_puthex(unsigned int n, char specifier)
 {
     char    *base;
   int     count;

     count = 0;
    if (specifier == 'x')
     base = "0123456789abcdef";
     else
       base = "0123456789ABCDEF";
     if (n >= 16)
       count += ft_puthex(n / 16, specifier);
    count += ft_putchar(base[n % 16]);
    return (count);
}

int    is_valid_format(char c)
{
    return (c == 'c' || c == 's' || c == 'p' || c == 'd'
        || c == 'i' || c == 'u' || c == 'x'
        || c == 'X' || c == '%');
}

int    handle_format(char specifier, va_list *args)
{
    if (specifier == 'x' || specifier == 'X')
        return (ft_puthex(va_arg(*args, unsigned int), specifier));

    return (0);
}

int    ft_printf(const char *format, ...)
{
    va_list        args;
    int            i;
    int            printed;

    printed = 0;
    i = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && is_valid_format(format[i + 1]))
        {
            i++;
            printed = handle_format(format[i], &args);
            printed++;
        }
        else
        {
            printed = ft_putchar(format[i]);
            printed++;
        }
        i++;
    }
    va_end(args);
    return (printed);
}

int    main(void)
{
    ft_printf("%x", 51966);
    
    return (0);
}