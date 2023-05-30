#ifndef MAIN_H_
#define MAIN_H_

#define BUFFER_SIZE 1024
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int _printf(const char *format, ...);

/***Protoypes for Functions used*******/
int p_c(char Buff[], int flags, int width, int precision, int size);
int p_s(char Buff[], int flags, int width, int precision,
		int size, va_list list);
int print_int(va_list list, char Buff[],
		int flags, int width, int precision, int size);
int print_custom_percent(va_list list, char Buff[],
	int flags, int width, int precision, int size);
int print_unsigned_binary(va_list list, char Buff[],
	int flags, int width, int precision, int size);
int print_modified_unsigned(va_list list, char Buff[],
	int flags, int width, int precision, int size);
int print_custom_octal(va_list list, char Buff[],
	int flags, int width, int precision, int size);
int write_buffer(char c, char Buff[],
	void flags, int width, int precision, int size);
int print_formatted_number(int neg, int buffInd, char Buff[],
	int flags, int width, int precision, int size);
int unsigned_digits(int neg, int buffInd, char Buff[],
	int flags, int width, int precision, int size);
int handleProcess(const char *format, int *buffInd, va_list list, char Buff[],
	int flags, int width, int precision, int size);
int writeMemoryAddress(char Buff[], int buffInd, int num_length,
	int width, int flags, char filler, char extra, int filler_start);
int num_writer(int buffInd, char Buff[],
	int flags, int width, int precision,
	int num_length, char filler, char extra);
void print_buffer(char Buff[], int *buffInd);

/*****Prototypes for Flags*****/
int calculate_flags(const char *format, int *index);
int calculate_width(const char *format, int *index, va_list list);
int calculatePrecision(const char *format, int *index, va_list list);
int calculateSize(const char *format, int *index);


#endif
