#include "main.h"

/**
 * isDigit - Checks if a character is a digit
 * @c: The character to check
 * Return: 1 if c is a digit, 0 otherwise
 */
int isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * appendHexCode - Appends ASCII in hexadecimal code to Buff
 * @Buff: Array of characters
 * @ind:tarting index to append
 * @asciiCode: ASCII code
 * Return: Always 3
 */
int appendHexCode(char asciiCode, char Buff[], int ind)
{
	char hexMap[] = "0123456789ABCDEF";

	Buff[ind++] = '\\';
	Buff[ind++] = 'x';
	Buff[ind++] = hexMap[asciiCode / 16];
	Buff[ind] = hexMap[asciiCode % 16];
	return (3);
}

/**
 * isPrintable - Checks if a character is printable
 * @c: The character to check
 * Return: 1 if c is printable, 0 otherwise
 */
int isPrintable(char c)
{
	return (c >= 32 && c < 127);
}

/**
 * convertSizeNumber - Casts a number to the specified size
 * @num: The number to be casted
 * @size: The size specifier
 * Return: The casted value of num
 */
long int convertSizeNumber(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short) num);
	return ((int) num);
}

/**
 * convertSizeUnsigned_int - Casts an unsigned number to
 * the specified size
 * @num: The number to be casted
 * @size: The size specifier
 * Return: The casted value of num
 */
unsigned long int convertSizeUnsigned_int(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short) num);
	return ((unsigned int) num);
}
