#include "main.h"
/**
 * process_Char - Process and prints a single character
 * @Buff: Buffer array
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size:size
 * @list: Argument list
 * Return: Number of characters printed
 */
int process_Char(va_list list, char Buff[], int flags,
		int width, int precision, int size)
{
	char c = (char)va_arg(list, int);

	return (write_buffer(c, Buff, flags, width, precision, size));
}
/**
 * process_string - function to process and print string
 * @Buff: Buffer array
 * @flags: flags
 * @width: Width
 * @list: Argument list of variable arguments
 * @precision: Precision
 * @size: size
 * Return: Number of characters printed
 */
int process_String(va_list list, char Buff[], int flags,
		int width, int precision, int size)
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
			write(1, &str[0], len);
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - len; a > 0; a--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));

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
int process_Percent(va_list list, char Buff[], int flags,
		int width, int precision, int size)
{
	char percent = '%';
	int chars_printed = 0;

	(void)list;
	(void)Buff;
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;

	chars_printed = write(1, &percent, 1);
	return (chars_printed);
}
