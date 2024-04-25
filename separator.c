#include "main.h"


/**
 * check_if_operator - Checks if the string is an operator.
 *
 * @s: String to compare.
 *
 * Return: 0 if ";", 1 if "&&", 2 if "||". Else -1.
 */
static int check_if_operator(char *s)
{
	int i;
	char operators[3][3] = {";\0", "&&", "||"};

	for (i = 0; i < 3; i++)
		if (_strcmp(s, operators[i]) == 0)
			return (i);

	return (-1);
}

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
		return (1);
	if (operator == 1)
		return (errorno == 0);
	if (operator == 2)
		return (!(errorno == 0));
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
	unsigned int i, len;
	int operator;

	if (!tokens || !tokens[0])
	{
		perror("Token array error");
		return (1);
	}
	for (i = 0, len = 1; tokens[i]; i++)
	{
		operator = check_if_operator(tokens[i]);
		if (operator >= 0)
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
	if (len == 1)
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
	subarray = realloc(subarray, sizeof(char *) * (*sub_len + 1));
	*sub_len += 1;
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
 * separator - Separates tokens[] elements into subarrays.
 *
 * @tokens: Malloc'd list of tokens.
 * @path_head: Head of PATH SLList.
 * @main_loop: Exit bool.
 */
void separator(char **tokens, Tlist *path_head, int *main_loop)
{
	unsigned int i, sub_len;
	int operator, skip;
	char **subarray;

	if (check_for_errors(tokens))
		return;
	subarray = malloc(sizeof(char *));
	if (!subarray)
	{
		perror("Malloc error");
		return;
	}
	for (i = 0, sub_len = 0, skip = 0; tokens[i]; i++)
	{
		operator = check_if_operator(tokens[i]);
		if (operator >= 0)
		{
			if (skip)
			{
				skip = 0;
				continue;
			}
			subarray = subarray_add(subarray, &sub_len, NULL);
			if (!subarray)
				return;
			execute_command(subarray, path_head, main_loop);
			if (execute_skipper(errno, operator))
				skip = 1;
			sub_len = 1;
		}
		else if (!skip)
		{
			subarray = subarray_add(subarray, &sub_len, tokens[i]);
			if (!subarray)
				return;
		}
	}
	if (sub_len > 0)
	{
		subarray = subarray_add(subarray, &sub_len, NULL);
		if (!subarray)
			return;
		execute_command(subarray, path_head, main_loop);
	}
	free(subarray);
}


