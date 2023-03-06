#include "shell.h"

/**
 * interact - returns true if shell is in interactive
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */

int interact(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * test_delim - checks if character is a delimeter
 * @ch: the character to check
 * @delim: the delineter string
 * Return: 1 if true, 0 otherwise
 */

int test_delim(char ch, char *delim)
{
	while (*delim)
		if (*delim++ == ch)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabets
 * @ch: the character to test
 * Return: 1 if ch is an alphabet, 0 otherwise
 */

int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts string to integer
 * @str: string to be converted
 * Return: 0 if no numbers in string, other
 */

int _atoi(char *str)
{
	int i, s = 1, f = 0, o;
	unsigned int r = 0;

	for (i = 0; str[i] != '\0' && f != 2; i++)
	{
		if (str[i] == '-')
			s *= -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			f = 1;
			r *= 10;
			r += (str[i] - '0');
		}
		else if (f == 1)
			f = 2;
	}
	if (s == -1)
		o = -r;
	else
		o = r;
	return (o);
}
