#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char bufer[],
	int flag, int width, int precision, int size)
{
	int q = BUFF_SIZE - 2;
	unsigned long int nam = va_arg(types, unsigned long int);

	nam = convert_size_unsgnd(nam, size);

	if (nam == 0)
		bufer[q--] = '0';

	bufer[BUFF_SIZE - 1] = '\0';

	while (nam > 0)
	{
		bufer[q--] = (nam % 10) + '0';
		nam /= 10;
	}

	q++;

	return (write_unsgnd(0, q, bufer, flag, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char bufer[],
	int flag, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		bufer[i--] = '0';

	bufer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		bufer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flag & F_HASH && init_num != 0)
		bufer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, bufer, flag, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char bufer[],
	int flag, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", bufer,
		flag, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char bufer[],
	int flag, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", bufer,
		flag, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char bufer[],
	int flag, char flag_cha, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		bufer[i--] = '0';

	bufer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		bufer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flag & F_HASH && init_num != 0)
	{
		bufer[i--] = flag_cha;
		bufer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, bufer, flag, width, precision, size));
}
