#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *mn, va_list list)
{
	int currr_mn = *mn + 1;
	int precision = -1;

	if (format[currr_mn] != '.')
		return (precision);

	precision = 0;

	for (currr_mn += 1; format[currr_mn] != '\0'; currr_mn++)
	{
		if (is_digit(format[currr_mn]))
		{
			precision *= 10;
			precision += format[currr_mn] - '0';
		}
		else if (format[currr_mn] == '*')
		{
			currr_mn++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*mn = currr_mn - 1;

	return (precision);
}
