#include "main.h"

/**
 * process_hexadecimal - Processes and prints an
 * unsigned number in hexadecimal notation
 * @list: List of arguments
 * @Buff: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size:ize specifier
 * Return: Number of characters printed
 */
int process_hexadecimal(va_list list, char Buff[],
	int flags, int width, int precision, int size)
{
	return (process_hexa(list, "0123456789abcdef", Buff,
		flags, 'x', width, precision, size));
}

/**
 * processHexaUpper - Prints unsigned number in uppercase hexadecimal notation
 * @list: List of arguments
 * @Buff: Buffer array to handle printing
 * @flags: Active flags for formatting
 * @width: Width specifier
 * @precision: Precision specifier
 * @size:ize specifier
 * Return: (Number of characters printed)
 */
int processHexaUpper(va_list list, char Buff[],
		int flags, int width, int precision, int size)
{
	return (process_hexa(list, "0123456789ABCDEF", Buff,
				flags, 'X', width, precision, size));
}

/**
 * process_hexa - Processes and prints a hexadecimal number
 * @list: List of arguments
 * @map_to: Array of values to map the number to
 * @Buff: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: Get width
 * @precision: Precision specification
 * @size:ize specifier
 * Return: Number of chars printed
 */
int process_hexa(va_list list, char map_to[], char Buff[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int a = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);
	unsigned long int init_num = num;

	(void)width;  /* Unused parameter */

	num = convertSizeUnsigned_int(num, size);

	if (num == 0)
		Buff[a--] = '0';

	Buff[BUFFER_SIZE - 1] = '\0';

	while (a >= 0 && num > 0)
	{
		Buff[a--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		Buff[a--] = flag_ch;
		Buff[a--] = '0';
	}

	a++;

	return (unsigned_digits(0, a, Buff, flags, width, precision, size));
}

