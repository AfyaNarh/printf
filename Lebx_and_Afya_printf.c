#include "main.h"

/**
 * print_buffer - Prints buffer contents
 * @Buff: Charater array
 * @buffInd: Buffer Index
 */
void print_buffer(char Buff[], int *buffInd)
{
	if (*buffInd > 0)
		write(1, &Buff[0], *buffInd);
	*buffInd = 0;
}

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	int a, processedChars = 0, flags, width, precision, size, buffInd = 0;
	va_list list;
	char Buff[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);
	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			Buff[buffInd++] = format[a];
			if (buffInd == BUFFER_SIZE)
			{
				print_buffer(Buff, &buffInd);
				processedChars += buffInd;
			}
			else
			{
				processedChars++;
			}
		}
		else
		{
			print_buffer(Buff, &buffInd);
			flags = calculate_flags(format, &a);
			width = calculate_width(format, &a, list);
			precision = calculatePrecision(format, &a, list);
			size = calculateSize(format, &a);
			++a;
			processedChars += handleProcess(format, &a, list, Buff,
				flags, width, precision, size);
		}
	}
	print_buffer(Buff, &buffInd);
	processedChars += buffInd;
	va_end(list);
	return (processedChars);
}
