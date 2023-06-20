#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - Prints sequence of integers from argument value to 98
 *
 * Description:  Modify value of 'target' to alter number to print to
 *
 * @n:           First value to be printed in sequence to 98
 *
 * Return:       None
 */

void print_to_98(int n)
{
	int i, target, comma = 0;

	target = 98;  /* Change this value to adjust number to print to */

	if (n <= target)
	{
		for (i = n; i <= target; i++)
		{
			comma == 0 ? comma = 1 : printf(", ");
			printf("%d", i);
		}
	}
	else
	{
		for (i = n; i >= target; i--)
		{
			comma == 0 ? comma = 1 : printf(", ");
			printf("%d", i);
		}
	}
	putchar('\n');
}
