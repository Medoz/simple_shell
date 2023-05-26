#include "master.h"

/**
 * print_char - print character.
 * @c: the char
 * Return: length.
 */

int print_char(char c)
{
	return (write(2, &c, 1));
}

/**
 * print_number - print number.
 * @n: output printed number
 */

void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		n1 = -n;
		print_char('-');
	}
	else
		n1 = n;

	if (n1 / 10)
		print_number(n1 / 10);

	print_char((n1 % 10) + '0');
}

/**
 * print_string - print string.
 * @s: the string length
 * Return: length.
 */

int print_string(char *s)
{
	return (write(2, s, _strlen(s)));
}

/**
 * num_len - return the number len
 * @n: number to be printed
 * Return: len.
 */

int num_len(int n)
{
	int len = 1;

	print_number(n);
	if (n < 0)
		len++;
	while (n /= 10)
		len++;

	return (len);
}

/**
 * specifier - print argument
 * @c: the specifier
 * @args: the arguments
 * Return: len.
 */

int specifier(char c, va_list args)
{
	int len = 0;
	char *str;

	if (c == 'c')
		len += print_char(va_arg(args, int));
	else if (c == 's')
	{
		str = va_arg(args, char *);
		len += print_string(STRING);
	}
	else if (c == 'i' || c == 'd')
		len += num_len(va_arg(args, int));
	else if (c == '%')
		len += print_char('%');
	else
	{
		len += print_char('%');
		len += print_char(c);
	}
	return (len);
}
