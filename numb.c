#include "monty.h"
#include <ctype.h>

/**
 * isNumb - function
 * description - check if is a number or not
 *
 * @s: passed the argument
 * Return: 1 if is int 0 otherwise
 */

int isNumb(char *s)
{
	int inter;

	for (inter = 0; s[inter] != '\n' && s[inter]; inter++)
	{
		if ((isdigit(s[inter]) == 0) && s[inter] != '-')
			return (0);
	}
	return (1);
}
