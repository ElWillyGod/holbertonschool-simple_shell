#include "main.h"

/**
 * _strlen - Gets length of a string.
 *
 * @str: String.
 *
 * Return: Len of (str).
 */
unsigned int _strlen(char *str)
{
	unsigned int len;

	for (len = 0; str[len]; len++)
		;

	return (len);
}


/**
 * _strcpy - Copies the content of a string to another. Including \0.
 *
 * @dest: Destiny.
 * @src: Source.
 *
 * Return: (dest)
 */
char *_strcpy(char *dest, char *src)
{
	unsigned int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];

	dest[i] = src[i];

	return (dest);
}

/**
 * _utoa - Unsigned int to string.
 *
 * @str: String to put uint.
 * @uinteger: Name says it all.
 * @ulen: Length of (uinteger). Passed to make fewer calculations.
 *
 * Return: (str)
 */
char *_utoa(char *str, unsigned int uinteger, unsigned int ulen)
{
	while (ulen > 0)
	{
		str[--ulen] = uinteger % 10 + 48;
		uinteger /= 10;
	}

	return (str);
}

/**
 * _strdup - Mallocs char * and copies the argument to the malloc'd space.
 *
 * @str: String to cpy.
 *
 * Return: Malloc'd space copy of (str).
 */

char *_strdup(char *str)
{
	char *cpy;

	if (!str)
		return (NULL);

	cpy = malloc(sizeof(char) * _strlen(str) + 1);

	if (cpy == NULL)
		return (NULL);

	_strcpy(cpy, str);

	return (cpy);
}

/**
 * _strcmp - Compares two strings.
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: returns 0 if they are equal, else the subtraction of s1 and s2
 */

int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}


