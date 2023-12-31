#include "main.h"

void print_bufer(char buffer[], int *buff_end);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, chars_printed = 0;
	int width, size, precision, flag, buff_end = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_end++] = format[i];
			if (buff_end == BUFF_SIZE)
				print_bufer(buffer, &buff_end);
			/* write(1, &format[i], 1);*/
			chars_printed++;
		}
		else
		{
			print_bufer(buffer, &buff_end);
			flag = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flag, width, precision, size);
			if (printed == -1)
				return (-1);
			chars_printed += printed;
		}
	}

	print_bufer(buffer, &buff_end);

	va_end(list);

	return (chars_printed);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_bufer(char buffer[], int *buff_end)
{
	if (*buff_end > 0)
		write(1, &buffer[0], *buff_end);

	*buff_end = 0;
}
