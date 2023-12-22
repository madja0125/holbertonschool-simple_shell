#include "sshell.h"

/**
 * is_empty - Function that verifies if the input is empty or
 * contains only whitespace.
 * @str: String to be checked.
 *
 * Return: 1 if the string is empty or contains only whitespace, 0 otherwise.
*/

int is_empty(const char *str)
{
	while (*str != '\0')
	{
		if (!isspace((unsigned char) *str))
		return (0);
		str++;
	}
	return (1);
}
