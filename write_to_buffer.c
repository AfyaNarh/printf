#include "main.h"

/**
 * write_buffer - Prints a string
 * @c: char types.
 * @Buff: Buffer array to handle print
 * @flags: Calculates active flags.
 * @width: Get width.
 * @precision: Precision specifier
 * @size:ize specifier
 *
 * Return: Number of chars printed.
 */
int write_buffer(char c, char Buff[],
	int flags, int width, int precision, int size)
{
	int a = 0;
	char filler = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		filler = '0';

	Buff[a++] = c;
	Buff[a] = '\0';

	if (width > 1)
	{
		Buff[BUFFER_SIZE - 1] = '\0';
		for (a = 0; a < width - 1; a++)
			Buff[BUFFER_SIZE - a - 2] = filler;

		if (flags & F_MINUS)
			return (write(1, &Buff[0], 1) +
					write(1, &Buff[BUFFER_SIZE - a - 1], width - 1));
		else
			return (write(1, &Buff[BUFFER_SIZE - a - 1], width - 1) +
					write(1, &Buff[0], 1));
	}

	return (write(1, &Buff[0], 1));
}

/**
 * print_formatted_number - Prints a formatted number
 * @neg: Flag indicating if the number is negative
 * @Index: index
 * @Buff: Buffer array to handle printing
 * @flags: Active flags for formatting
 * @width: Width specifier
 * @precision: Precision specifier
 * @size:ize specifier (unused)
 *
 * Return: Number of characters printed
 */
int print_formatted_number(int neg, int Index, char Buff[],
	int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - Index - 1;
	char filler = (flags & F_ZERO && !(flags & F_MINUS)) ? '0' : ' ';
	char extra = 0;

	UNUSED(size);

	if (neg)
		extra = '-';
	else if (flags & F_PLUS)
		extra = '+';
	else if (flags & F_SPACE)
		extra = ' ';

	return (num_writer(Index, Buff, flags, width, precision,
				length, filler, extra));
}

/**
 * unsigned_digits - Writes an unsigned number
 * @neg: Flag indicating if the number is negative
 * @Index: Index at which the number starts
 * @Buff: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size:ize specifier
 *
 * Return: Number of written chars.
 */
int unsigned_digits(int neg, int Index, char Buff[],
	int flags, int width, int precision, int size)
{
	int length = BUFFER_SIZE - Index - 1;
	int a = 0;
	char filler = ' ';

	UNUSED(neg);
	UNUSED(size);

	if (precision == 0 && Index == BUFFER_SIZE - 2 && Buff[Index] == '0')
		return (0);

	if (precision > 0 && precision < length)
		filler = ' ';

	while (precision > length)
		Buff[--Index] = '0', length++;

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		filler = '0';

	if (width > length)
	{
		for (a = 0; a < width - length; a++)
			Buff[a] = filler;

		Buff[a] = '\0';

		if (flags & F_MINUS)
			return (write(1, &Buff[Index], length) + write(1, &Buff[0], a));
		else
			return (write(1, &Buff[0], a) + write(1, &Buff[Index], length));
	}

	return (write(1, &Buff[Index], length));
}

/**
 * handleProcess - Process an argument based on its type
 * @format: Formatted string in which to process the arguments.
 * @list: List of arguments to be processed.
 * @Index: Index in the buffer array.
 * @Buff: Buffer array to handle process.
 * @flags: Active flags.
 * @width: Width specifier.
 * @precision: Precision specifier.
 * @size:ize specifier.
 * Return: Number of characters processed.
 */
int handleProcess(const char *format, int *Index, va_list list, char Buff[],
	int flags, int width, int precision, int size)
{
	int a, numProcessed = 0, processedChars = -1;
	FmtSpec_t fmtSpecifiers[] = {
		{'c', process_Char}, {'s', process_String}, {'%', process_Percent},
		{'i', process_Int}, {'d', process_Int}, {'b', process_Binary},
		{'u', process_Unsigned}, {'o', process_Octal}, {'x', process_hexadecimal},
		{'X', processHexaUpper}, {'p', process_pointer},
		{'S', process_non_printable}, {'r', process_reverse},
		{'R', process_rot13string}, {'\0', NULL}
	};
	for (a = 0; fmtSpecifiers[a].sp != '\0'; a++)
	{
		if (format[*Index] == fmtSpecifiers[a].sp)
			return (fmtSpecifiers[a].fn(list, Buff, flags, width, precision, size));
	}

	if (fmtSpecifiers[a].sp == '\0')
	{
		if (format[*Index] == '\0')
			return (-1);
		numProcessed += write(1, "%%", 1);
		if (format[*Index - 1] == ' ')
			numProcessed += write(1, " ", 1);
		else if (width)
		{
			--(*Index);
			while (format[*Index] != ' ' && format[*Index] != '%')
				--(*Index);
			if (format[*Index] == ' ')
				--(*Index);
			return (1);
		}
		numProcessed += write(1, &format[*Index], 1);
		return (numProcessed);
	}
	return (processedChars);
}
