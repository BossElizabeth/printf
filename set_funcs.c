#include "main.h"

/**
 * get_func - checks for the specifier
 * @v: variable to the function
 * Return: function
 */
int (*get_func(char v))(va_list)
{
	int i = 0;
	spec arr[] = {
		{"c", print_c},
		{"s", print_s},
		{"%", print_percent},
		{"d", print_d},
		{"i", print_i},
		{NULL, NULL}
	};
	while (arr[i].valid)
	{
		if (v == arr[i].valid[0])
			return (arr[i].f);
		i++;
	}
	return (NULL);
}
