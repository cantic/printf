#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Prints output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
va_list args;
int count = 0;
char c, *str;

va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;

switch (*format)
{
case 'c':
c = va_arg(args, int);
count += write(1, &c, 1);
break;
case 's':
str = va_arg(args, char *);
while (*str)
count += write(1, str++, 1);
break;
case '%':
count += write(1, "%", 1);
break;
default:
count += write(1, format, 1);
break;
}
}
else
count += write(1, format, 1);
format++;
}
va_end(args);
return (count);
}
