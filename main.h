#ifndef MAIN_H_
#define MAIN_H_

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE (1024)

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

#define S_LONG 2
#define S_SHORT 1

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);

/**
 * struct FS - Struct for format specifier and associated function
 *
 * @sp: The format specifier.
 * @fn: The associated function.
 */
struct FS
{
	char sp;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct FS FmtSpec_t - Typedef for FS struct
 *
 * @sp: The format specifier.
 * @fn: The associated function.
 */
typedef struct FS FmtSpec_t;

/***Protoypes for Functions used*******/
int process_Char(va_list list, char Buff[], int flags,
		int width, int precision, int size);
int process_String(va_list list, char Buff[], int flags,
		int width, int precision, int size);
int process_Int(va_list list, char Buff[],
		int flags, int width, int precision, int size);
int process_Percent(va_list list, char Buff[], int flags,
		int width, int precision, int size);
int process_Binary(va_list list, char Buff[],
	int flags, int width, int precision, int size);
int process_Unsigned(va_list list, char Buff[],
	int flags, int width, int precision, int size);
int process_Octal(va_list list, char Buff[],
	int flags, int width, int precision, int size);
int write_buffer(char c, char Buff[],
	int flags, int width, int precision, int size);
int print_formatted_number(int neg, int Index, char Buff[],
	int flags, int width, int precision, int size);
int unsigned_digits(int neg, int Index, char Buff[],
	int flags, int width, int precision, int size);
int handleProcess(const char *format, int *Index, va_list list, char Buff[],
	int flags, int width, int precision, int size);
int writeMemoryAddress(char Buff[], int Index, int num_length,
	int width, int flags, char filler, char extra, int filler_start);
int num_writer(int ind, char Buff[],
	int flags, int width, int precision,
	int num_length, char filler, char extra);
void print_buffer(char Buff[], int *buffInd);
int process_pointer(va_list list, char Buff[],
		int flags, int width, int precision, int size);
int process_non_printable(va_list list, char Buff[],
		int flags, int width, int precision, int size);
int process_reverse(va_list list, char buffer[],
		int flags, int width, int precision, int size);
int process_rot13string(va_list list, char Buff[],
		int flags, int width, int precision, int size);
int process_hexadecimal(va_list list, char Buff[],
	int flags, int width, int precision, int size);
int processHexaUpper(va_list list, char Buff[],
		int flags, int width, int precision, int size);
int process_hexa(va_list list, char map_to[], char Buff[],
		int flags, char flag_ch, int width, int precision, int size);
int process_pointer(va_list list, char Buff[],
		int flags, int width, int precision, int size);

int calculate_flags(const char *format, int *index);
int calculate_width(const char *format, int *index, va_list list);
int calculatePrecision(const char *format, int *index, va_list list);
int calculateSize(const char *format, int *index);

int isDigit(char c);
int appendHexCode(char asciiCode, char Buff[], int ind);
int isPrintable(char c);
long int convertSizeNumber(long int num, int size);
unsigned long int convertSizeUnsigned_int(unsigned long int num, int size);

#endif
