#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *m)
{
	int cur_m = *m + 1;
	int size = 0;

	if (format[cur_m] == 'l')
		size = S_LONG;
	else if (format[cur_m] == 'h')
		size = S_SHORT;

	if (size == 0)
		*m = cur_m - 1;
	else
		*m = cur_m;

	return (size);
}
