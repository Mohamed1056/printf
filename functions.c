#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_string(va_list types, char bufer[],
	int flag, int width, int precision, int size)
{
	int length = 0, x;
	char *ptr = va_arg(types, char *);
	
	UNUSED(bufer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (ptr == NULL)
	{
		ptr = "(null)";
		if (precision >= 6)
			ptr = "      ";
	}

	while (ptr[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flag & F_MINUS)
		{
			write(1, &ptr[0], length);
			for (x = width - length; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - length; x > 0; x--)
				write(1, " ", 1);
			write(1, &ptr[0], length);
			return (width);
		}
	}

	return (write(1, ptr, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_percent(va_list types, char bufer[],
	int flag, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(bufer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char bufer[],
	int flag, int width, int precision, int size)
{
	int m = BUFF_SIZE - 2;
	int is_it_negative = 0;
	long int z = va_arg(types, long int);
	unsigned long int num;

	z = convert_size_number(z, size);

	if (z == 0)
		bufer[m--] = '0';

	bufer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)z;

	if (z < 0)
	{
		num = (unsigned long int)((-1) * z);
		is_it_negative = 1;
	}

	while (num > 0)
	{
		bufer[m--] = (num % 10) + '0';
		num /= 10;
	}

	m++;

	return (write_number(is_it_negative, m, bufer, flag, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char bufer[],
	int flag, int width, int precision, int size)
{
	unsigned int x, m, j, summ;
	unsigned int l[32];
	int count;

	UNUSED(bufer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	l[0] = x / m;
	for (j = 1; j < 32; j++)
	{
		m /= 2;
		l[j] = (x / m) % 2;
	}
	for (j = 0, summ = 0, count = 0; j < 32; j++)
	{
		summ += l[j];
		if (summ || j == 31)
		{
			char zoo = '0' + l[j];

			write(1, &zoo, 1);
			count++;
		}
	}
	return (count);
}
