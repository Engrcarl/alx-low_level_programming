#include "main.h"
#include <stdio.h>
/**
 * binary_to_uint - function to convert binary to unsigned int
 * @b: pointer to char string input
 * Return: always successful
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	unsigned int y = 1;
	int x;

	if (b == NULL)
		return (0);
	x = 0;
	while (b[x] != '\0')
	{
		if (b[x] != '0' && b[x] != '1')
		{
			return (0);
		}
		num <<= 1;
		if (b[x] == '1')
		{
			num ^= y;
		}
		x++;
	}
	return (num);
}
