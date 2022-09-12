#include "header.h"
/**
 * _putchar - function to print
 * @c: character
 * Return: no zero
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printf_c - function to print characters
 * @flist: list of arguments
 * Return: no zero
 */
int _printf_c(va_list flist)
{
	char c;

	c = va_arg(flist, int);
	return (write(1, &c, 1));
}
/**
 * _printf_s - function to print strings
 * @flist: list of arguments
 * Return: no zero
 */
int _printf_s(va_list flist)
{
	char *ptr = NULL, *_null = "(null)";
	unsigned int len = 0;

	ptr = va_arg(flist, char *);
	if (ptr == NULL)
	{
		ptr = _null;
	}
	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
		len++;
	}
	return (len);
}
