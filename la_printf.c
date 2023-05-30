#include "main.h"
/**
 * process_Char - Process and prints a single character
 * @Buff: Buffer array
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size:size
 * Return: Number of characters printed
 */
int process_Char(char Buff[], int flags, int width, int precision, int size)
{
	va_list list;
	char c;
	int printed_chars;

	c = (char)va_arg(list, int);

	printed_chars = write_buffer(c, Buff, flags, width, precision, size);
	return (printed_chars);
}
/**
 * process_String - function to process and print string
 * @Buff: Buffer array
 * @flags: flags
 * @width: Width
 * @list: Argument list of variable arguments
 * @precision: Precision
 * @size: size
 * Return: Number of characters printed
 */
int process_String(char Buff[], int flags, int width,
		int precision, int size, va_list list)
{
	int len = 0, a;
	char *str = va_arg(list, char *);

	UNUSED(Buff);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

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
			for (a = 0; a < len; a++)
				write(1, &str[a], 1);
			for (a = 0; a < width - len; a++)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = 0; a < width - len; a++)
				write(1, " ", 1);
			for (a = 0; a < len; a++)
				write(1, &str[a], 1);
			return (width);
		}
	}
	for (a = 0; a < len; a++)
		write(1, &str[a], 1);
	return (len);
}


/**
 * process_Int - process and prints an integer
 * @list: argument list
 * @Buff: Buffer array
 * @flags: flags
 * @width: Width
 * @precision: Precision
 * @size: size
 * Return: Number of characters printed
 */
int process_Int(va_list list, char Buff[],
		int flags, int width, int precision, int size)
{
	int a = BUFFER_SIZE - 2;
	int neg = 0;
	long int c = va_arg(list, long int);
	unsigned long int num;

	c = convertSizeNumber(c, size);

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

	return (print_formatted_number(neg, a + 1, Buff,
				flags, width, precision, size));
}

/**
 * process_Percent - Prints a percent sign
 * @list: List of arguments (unused)
 * @Buff: Buffer array to process and print (unused)
 * @flags: Calculates flags (unused)
 * @width: Get width (unused)
 * @precision: Precision specification (unused)
 * @size:size specifier (unused)
 * Return: Number of characters printed
 */
int process_Percent(va_list list, char Buff[],
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
