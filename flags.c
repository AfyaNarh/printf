#include "main.h"

/**
 * calculate_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @index: Current index in the format string
 *
 * Return: Flags
 */
int calculate_flags(const char *format, int *index)
{
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	int currIndex = *index + 1;
	int flags = 0;

	while (format[currIndex] != '\0')
	{
		int a;

		for (a = 0; FLAGS_CH[a] != '\0'; a++)
		{
			if (format[currIndex] == FLAGS_CH[a])
			{
				flags |= FLAGS_ARR[a];
				break;
			}
		}

		if (FLAGS_CH[a] == 0)
			break;

		currIndex++;
	}

	*index = currIndex - 1;

	return (flags);
}

/**
 * calculate_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments
 * @index: Current index in the format string
 * @list: List of arguments
 *
 * Return: Width
 */
int calculate_width(const char *format, int *index, va_list list)
{
	int currIndex;
	int width = 0;

	for (currIndex = *index + 1; format[currIndex] != '\0'; currIndex++)
	{
		if (isDigit(format[currIndex]))
		{
			width *= 10;
			width += format[currIndex] - '0';
		}
		else if (format[currIndex] == '*')
		{
			currIndex++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*index = currIndex - 1;

	return (width);
}


/**
 * calculatePrecision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @index: Index in the format string
 * @list: List of arguments
 *
 * Return: Precision value
 */
int calculatePrecision(const char *format, int *index, va_list list)
{
	int currIndex = *index + 1;
	int precision = -1;

	if (format[currIndex] != '.')
		return (precision);

	precision = 0;

	for (currIndex += 1; format[currIndex] != '\0'; currIndex++)
	{
		if (isDigit(format[currIndex]))
		{
			precision *= 10;
			precision += format[currIndex] - '0';
		}
		else if (format[currIndex] == '*')
		{
			currIndex++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*index = currIndex - 1;

	return (precision);
}


/**
 * calculateSize - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @index: Index in the format string
 *
 * Return: Size specifier value
 */
int calculateSize(const char *format, int *index)
{
	int currIndex = *index + 1;
	int size = 0;

	if (format[currIndex] == 'l')
		size = S_LONG;
	else if (format[currIndex] == 'h')
		size = S_SHORT;

	if (size == 0)
		*index = currIndex - 1;
	else
		*index = currIndex;

	return (size);
}

