#include "main.h"

/**
 * writeMemoryAddress - Write a memory address
 * @Buff: Array of chars
 * @buffInd: Index at which the number starts in the buffer
 * @num_length: Length of the number
 * @width: Width specifier
 * @flags: Flags specifier
 * @filler: Padding character
 * @extra: Extra character
 * @filler_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int writeMemoryAddress(char Buff[], int buffInd, int num_length,
	int width, int flags, char filler, char extra, int filler_start)
{
	int a;

	if (width > num_length)
	{
		for (a = 3; a < width - num_length + 3; a++)
			Buff[a] = filler;
		Buff[a] = '\0';

		if (flags & F_MINUS && filler == ' ')
		{
			Buff[--buffInd] = 'x';
			Buff[--buffInd] = '0';
			if (extra)
				Buff[--buffInd] = extra;
			return (write(1, &Buff[buffInd], num_length) + write(1, &Buff[3], a - 3));
		}
		else if (!(flags & F_MINUS) && filler == ' ')
		{
			Buff[--buffInd] = 'x';
			Buff[--buffInd] = '0';
			if (extra)
				Buff[--buffInd] = extra;
			return (write(1, &Buff[3], a - 3) + write(1, &Buff[buffInd], num_length));
		}
		else if (!(flags & F_MINUS) && filler == '0')
		{
			if (extra)
				Buff[--filler_start] = extra;
			Buff[1] = '0';
			Buff[2] = 'x';
			return (write(1, &Buff[filler_start], a - filler_start) +
				write(1, &Buff[buffInd], num_length - (1 - filler_start) - 2));
		}
	}

	Buff[--buffInd] = 'x';
	Buff[--buffInd] = '0';
	if (extra)
		Buff[--buffInd] = extra;
	return (write(1, &Buff[buffInd], BUFFER_SIZE - buffInd - 1));
}

/**
 * num_writer - Writes a number using a buffer
 * @ind: starting index of the number in the buffer
 * @Buff: Buffer
 * @flags: Flags
 * @width: Width
 * @preSpec: Precision
 * @len: Length of the number
 * @filler: Padding character
 * @extra: Extra character
 *
 * Return: Number of printed characters.
 */
int num_writer(int ind, char Buff[], int flags, int width,
		int preSpec, int len, char filler, char extra)
{
	int a, filler_start = 1;

	if (preSpec == 0 && ind == BUFFER_SIZE - 2 && Buff[ind] == '0' && width == 0)
		return (0);
	if (preSpec == 0 && ind == BUFFER_SIZE - 2 && Buff[ind] == '0')
		Buff[ind] = filler = ' ';
	if (preSpec > 0 && preSpec < len)
		filler = ' ';
	while (preSpec > len)
		Buff[--ind] = '0', len++;
	if (extra != 0)
		len++;
	if (width > len)
	{
		for (a = 1; a < width - len + 1; a++)
			Buff[a] = filler;
		Buff[a] = '\0';
		if (flags & F_MINUS && filler == ' ')
		{
			if (extra)
				Buff[--ind] = extra;
			return (write(1, &Buff[ind], len) + write(1, &Buff[1], a - 1));
		}
		else if (!(flags & F_MINUS) && filler == ' ')
		{
			if (extra)
				Buff[--ind] = extra;
			return (write(1, &Buff[1], a - 1) + write(1, &Buff[ind], len));
		}
		else if (!(flags & F_MINUS) && filler == '0')
		{
			if (extra)
				Buff[--filler_start] = extra;
			return (write(1, &Buff[filler_start], a - filler_start) +
				write(1, &Buff[ind], len - (1 - filler_start)));
		}
	}
	if (extra)
		Buff[--ind] = extra;
	return (write(1, &Buff[ind], len));
}

