#ifndef MAIN_H_
#define MAIN_H_

#define BUFFER_SIZE 1024

int p_c(char Buff[], int flags, int width, int precision, int size);
int p_s(char Buff[], int flags, int width, int precision,
		int size, va_list list);
int print_int(va_list list, char Buff[],
		int flags, int width, int precision, int size);

#endif