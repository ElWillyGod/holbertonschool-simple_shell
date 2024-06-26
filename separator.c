#include "main.h"


/**
 * execute_skipper - Check if the next execve is to be skipped.
 *
 * @errorno: errno.
 * @operator: 0 for ";", 1 for "&&", "2" for "||".
 *
 * Return: 0 to skip, 1 to not skip, -1 error (not skip).
 */
static int execute_skipper(int errorno, int operator)
{
	if (operator == 0)
		return (0);
	if (operator == 1)
		return (errorno != 0);
	if (operator == 2)
		return (errorno == 0);
	return (-1);
}

/**
 * check_for_errors - Checks if there's any errors before running separator.
 *
 * @tokens: Malloc'd token array.
 *
 * Return: 1 if error, else 0.
 */
static int check_for_errors(char **tokens)
{
	unsigned int i, l, len;

	for (i = 0, l = 3, len = 1; tokens[i]; i++)
	{
		l = 3;
		if (_strcmp(tokens[i], ";") == 0)
			l = 0;
		else if (_strcmp(tokens[i], "&&") == 0)
			l = 1;
		else if (_strcmp(tokens[i], "||") == 0)
			l = 2;
		if (l != 3)
		{
			if (len == 1)
			{
				perror("Operator w/o first arg");
				return (1);
			}
			len = 1;
		}
		else
		{
			len += 1;
		}
	}
	if (l != 3 && len == 1)
	{
		perror("Operator w/o second arg");
		return (1);
	}
	return (0);
}

/**
 * subarray_add - Adds an element to subarray.
 *
 * Reminder: Elements are freed in main. This only saves a pointer to them.
 *
 * @subarray: Malloc'd subarray array.
 * @sub_len: Len of subarray.
 * @s: Token to add.
 *
 * Return: Pointer to realloc'd subarray.
 */
static char **subarray_add(char **subarray, unsigned int *sub_len, char *s)
{
	*sub_len += 1;
	subarray = _realloc(subarray, (*sub_len - 1) * sizeof(char *),
			sizeof(char *) * *sub_len);
	if (!subarray)
	{
		perror("Realloc error");
		free(subarray);
		return (NULL);
	}

	subarray[*sub_len - 1] = s;

	return (subarray);
}

/**
 * go_through_tokens - asdfg
 *
 * @tokens: asdfg
 * @subarray: asdfg
 * @sub_len: asdfg
 * @path_head: asdfg
 * @main_loop: asdfg
 * @shell_name: Name of shell.
 *
 * Return: asdfg
 */
char **go_through_tokens(char **tokens, char **subarray, unsigned int *sub_len,
		Tlist *path_head, int *main_loop, char *shell_name)
{
	unsigned int i, l;
	int skip;

	for (i = 0, *sub_len = 0, skip = 0; tokens[i]; i++)
	{
		l = 3;
		if (_strcmp(tokens[i], ";") == 0)
			l = 0;
		else if (_strcmp(tokens[i], "&&") == 0)
			l = 1;
		else if (_strcmp(tokens[i], "||") == 0)
			l = 2;
		if (l != 3)
		{
			if (skip)
			{
				skip = 0;
				continue;
			}
			subarray = subarray_add(subarray, sub_len, NULL);
			if (!subarray)
				return (NULL);
			execute_command(subarray, path_head, main_loop,
					shell_name);
			if (execute_skipper(errno, l))
				skip = 1;
			*sub_len = 0;
		}
		else if (!skip)
		{
			subarray = subarray_add(subarray, sub_len, tokens[i]);
			if (!subarray)
				return (NULL);
		}
	}
	return (subarray);
}

/**
 * separator - Separates tokens[] elements into subarrays.
 *
 * @tokens: Malloc'd list of tokens.
 * @path_head: Head of PATH SLList.
 * @main_loop: Exit bool.
 * @shell_name: Name of shell.
 */
void separator(char **tokens, Tlist *path_head, int *main_loop,
		char *shell_name)
{
	char **subarray;
	unsigned int sub_len;

	if (check_for_errors(tokens))
		return;
	subarray = malloc(sizeof(char *));
	if (!subarray)
	{
		perror("Malloc error");
		return;
	}
	subarray = go_through_tokens(tokens, subarray, &sub_len,
			path_head, main_loop, shell_name);
	if (!subarray)
		return;
	if (sub_len > 0)
	{
		subarray = subarray_add(subarray, &sub_len, NULL);
		if (!subarray)
			return;
		execute_command(subarray, path_head, main_loop, shell_name);
	}
	free(subarray);
}


