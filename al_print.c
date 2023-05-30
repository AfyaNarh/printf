#include "main.h"

/**
 * process_Binary - Prints an unsigned number in binary format
 * @list: List of arguments
 * @Buff: Buffer array
 * @flags: calculates flags
 * @width: Width calculator
 * @precision: Precision calculator
 * @size: size calculator
 * Return: Number of characters printed
 */
int process_Binary(va_list list, char Buff[],
	int flags, int width, int precision, int size)
{
	unsigned int a, b, c, d, total;
	unsigned int binary[32];
	int Total;

	(void)Buff;
	(void)flags;
	(void)width;
	(void)precision;
	(void)size;

	a = va_arg(list, unsigned int);
	b = 2147483648;
	binary[0] = a / b;
	for (c = 1; c < 32; c++)
	{
		b /= 2;
		binary[c] = (a / b) % 2;
	}

	for (c = 31, total = 0, Total = 0; c >= 0; c--)
	{
		total += binary[c];
		d = binary[c] + '0';

		if (total || c == 0)
		{
			write(1, &d, 1);
			Total++;
		}
	}
	return (Total);
}


/**
 * process_Unsigned - Prints an unsigned number
 * @list: List of arguments
 * @Buff: Buffer array
 * @flags: Calculates flags
 * @width: Width calculator
 * @precision: Precision calculator
 * @size: size calculator
 * Return: Number of characters printed
 */
int process_Unsigned(va_list list, char Buff[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);

	num = unsigned_size(num, size);

	if (num == 0)
		Buff[a--] = '0';

	Buff[BUFF_SIZE - 1] = '\0';

	do {
		Buff[a--] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	a++;

	return (unsigned_digits(0, a, Buff, flags, width, precision, size));
}

/**
 * process_Octal - Prints an unsigned number in octal notation
 * @list: List of arguments
 * @Buff: Buffer array
 * @flags: Calculates active flags
 * @width: Calculates width
 * @precision:Calculates  Precision
 * @size: Calculates size
 * Return: Number of characters printed
 */
int process_Octal(va_list list, char Buff[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);
	unsigned long int init_num = num;

	(void)width;

	num = unsignd_size(num, size);

	if (num == 0)
		Buff[a--] = '0';

	Buff[BUFF_SIZE - 1] = '\0';

	while (a >= 0)
	{
		Buff[a--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		Buff[a--] = '0';

	a++;

	return (Unsigned_digits(0, a, Buff, flags, width, precision, size));
}
