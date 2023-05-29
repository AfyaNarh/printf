#include "main.h"
/**
 * p_c - Prints a single character
 * @Buff: Buffer array
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size:ize
 * Return: Number of characters printed
 */
int p_c(char Buff[], int flags, int width, int precision, int size)
{
	va_list list;
	char character;
	int printed_chars;

	va_start(list, Buff);
	character = (char)va_arg(list, int);
	va_end(list);

	printed_chars = write_buffer(character, Buff, flags, width, precision, size);
	return (printed_chars);
}
/**
 * p_s - Prints string
 * @Buff: Buffer array
 * @flags: flags
 * @width: Width
 * @precision: Precision
 * @size:ize
 * list: argument list
 * Return: Number of characters printed
 */
int p_s(char Buff[], int flags, int width, int precision,
		int size, va_list list)
{
	int len = 0, i;

	char *str = va_arg(list, char *);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & F_MINUS)
		{
			for (i = 0; i < len; i++)
				write(1, &str[i], 1);
			for (i = 0; i < width - len; i++)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = 0; i < width - len; i++)
				write(1, " ", 1);
			for (i = 0; i < len; i++)
				write(1, &str[i], 1);
			return (width);
		}
	}
	for (i = 0; i < len; i++)
		write(1, &str[i], 1);
	return (len);
}


/**
 * print_int - Prints an integer
 * @list: argument list
 * @Buff: Buffer array to handle print
 * @flags: flags
 * @width: Width
 * @precision: Precision
 * @size: size
 * Return: Number of characters printed
 */
int print_int(va_list list, char Buff[],
		int flags, int width, int precision, int size)
{
	int a = BUFFER_SIZE - 2;
	int neg = 0;
	long int c = va_arg(list, long int);
	unsigned long int num;

	c = convert(c, size);

	if (c == 0)

		Buff[a--] = '0';

	Buff[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)c;

	if (c < 0)
	{
		num = (unsigned long int)((-1) * c);
		neg = 1;
	}

	do {
		Buff[a--] = (num % 10) + '0';
		num /= 10;
	} while (a >= 0 && num != 0);

	return (write_number(neg, a + 1, Buff, flags, width, precision, size));
}

/**
 * print_custom_percent - Prints a percent sign
 * @list: List of arguments (unused)
 * @Buff: Buffer array to handle print (unused)
 * @flags: Calculates active flags (unused)
 * @width: Get width (unused)
 * @precision: Precision specification (unused)
 * @size:ize specifier (unused)
 * Return: Number of characters printed
 */
int print_custom_percent(va_list list, char Buff[],
	int flags, int width, int precision, int size)
{
	char percent = '%';
	int chars_printed = 0;

	(void)list;        /*uppress unused parameter warning */
	(void)Buff;
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;

	chars_printed = write(1, &percent, 1);
	return (chars_printed);
}
