#include "main.h"
/**
 * process_pointer - Processes and prints the value of a pointer variable
 * @list: List of arguments
 * @Buff: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed.
 */
int process_pointer(va_list list, char Buff[],
		int flags, int width, int precision, int size)
{
	char extra = 0, filler = ' ';
	int ind = BUFFER_SIZE - 2, length = 2, filler_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(list, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	Buff[BUFFER_SIZE - 1] = '\0';
	UNUSED(precision);
	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		Buff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		filler = '0';
	if (flags & F_PLUS)
		extra = '+', length++;
	else if (flags & F_SPACE)
		extra = ' ', length++;
	ind++;

	return (writeMemoryAddress(Buff, ind, length,
				width, flags, filler, extra, filler_start));
}

/**
 * process_non_printable - Processes and prints ASCII codes in hexadecimal
 *                        for non-printable characters
 * @list: Argument list
 * @Buff: Buffer array
 * @flags: Calculates flags
 * @width: calculate width
 * @precision: calculate Precision
 * @size: calculate Size
 * Return: Number of characters printed.
 */
int process_non_printable(va_list list, char Buff[],
		int flags, int width, int precision, int size)
{
	int a = 0, offset_value = 0;
	char *str = va_arg(list, char *);

	void UNUSED(flags);
	void UNUSED(width);
	void UNUSED(precision);
	void UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	for (; str[a]; a++)
	{
		if (isPrintable(str[a]))
			Buff[a + offset_value] = str[a];
		else
			offset_value += append_hexa_code(str[a], Buff, a + offset_value);
	}
	Buff[a + offset_value] = '\0';

	return (write(1, Buff, a + offset_value));
}


/**
 * process_reverse - Process and print a string in reverse order.
 * @list: List of arguments.
 * @buffer: Buffer array for print handling.
 * @flags: Active flags for formatting.
 * @width: Width specification.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: Number of characters printed.
 */
int process_reverse(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int total = 0;
	int length = 0, a;

	void(buffer);
	void(flags);
	void(width);
	void(precision);
	void(size);

	str = va_arg(list, char *);

	if (str == NULL)
	{
		str = "(Null)";
	}

	/* Calculate the length of the string */
	while (str[length] != '\0')
		length++;

	/* Print the string in reverse order */
	for (a = length - 1; a >= 0; a--)
	{
		char ch = str[a];

		write(1, &ch, 1);
		total++;
	}

	return (total);
}

