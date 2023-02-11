#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * _printf - Custum printf function
 * @format: A string containing the caracters to print
 * Return: the count of the printed charecters
 */

int _printf(const char *format, ...)
{
	va_list args;
	int num, count = 0;
	int i, k, length, len, l;
	char c, *ptr, *dig;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				count += write(1, &c, 1);
			}
			if (format[i] == 's')
			{
				ptr = va_arg(args, char*);
				if (ptr == NULL)
				{
		      			ptr = "(null)";
				}
		    		for (length = 0; ptr[length]; length++)
				{
	      				;
				}
				count += write(1, ptr, length);
			}
			if (format[i] == '%')
				count += write(1, &format[i], 1);
			if (format[i] == '\0')
				count += write(1, &format[i-1],1);
			if (format[i] == 'd' || format[i] == 'i')
			{
				num = va_arg(args, int);
				k = num;
				len = 0;
				while (k >= 1)
				{				
					len++;
					k /= 10;
				}
				dig = malloc(len + 1);
				dig[len] = '\0';
				for (l = 1; l < len + 1; l++)
				{
					dig[len - l] = (num % 10) + '0';
					num /= 10;
				}
				count += write(1, dig, len);
				free(dig);
				dig = NULL;
			}
		}
		else
			count += write(1, &format[i], 1);
	}
	va_end(args);
	return (count);
}
