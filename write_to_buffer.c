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
	void flags, int width, int precision, int size)
{ /* char is stored at left and padding at Buff's right */

	int a = 0;
	char filler = ' ';

	void UNUSED(precision);
	void UNUSED(size);

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
