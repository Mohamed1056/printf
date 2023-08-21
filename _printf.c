#include"main.h"

/**
 * _printf - variadic function like
 * built-in function printf
 * @format: takes the input of the function
 * Return: count_num
*/

int _printf(const char *format, ...)
{
	int count_num = 0;
	va_list list;
	/*check if format is null or not*/
	if (format == NULL)
		return (-1);
	va_start(list, format);
	while (*format)/*a loop going through format string*/
	{
		if (*format != '%')/*checking if all the characters in format don't equal %*/
		{
			write(1, format, 1);/*using write function to print the string*/
			count_num++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')/*this will return %%*/
			{
				write(1, format, 1);
				count_num++;
			}
			else if (*format == 'c')/*checking for characters*/
			{
				char car = va_arg(list, int);

				write(1, &car, 1);
				count_num++;
			}
			else if (*format == 's')/*checking for string*/
			{
				char *str = va_arg(list, char *);

				write(1, str, strlen(str));
				count_num += strlen(str);
			}
		}
		format++;
	}
	va_end(list);
	return (count_num);
}
