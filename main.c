#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define RED "\033[31m"
#define RESET "\033[0m"

/**
 * free_tokens - Frees the malloc'd tokens in the tokens list.
 *
 * @tokens: Token list.
 */
static void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);
}

/**
 * add_token_to_tokens - Adds a mallocd string cpy of token arg to tokens.
 *
 * @token: String to be malloc'd and inserted.
 * @tokens_size: Size of list of tokens (tokens).
 * @tokens: Malloc'd list of tokens.
 *
 * Return: Reallocated pointer of tokens.
 */
static char **add_token_to_tokens(const char *token, size_t *tokens_size,
		char ***tokens)
{
	char *mallocd_token;
	char **mallocator;

	*tokens_size += 1;
	mallocator = realloc(*tokens, sizeof(char **) * (*tokens_size));
	if (!*mallocator)
	{
		/* handle malloc fail */
	}
	*tokens = mallocator;

	if (token)
	{
		mallocd_token = _strdup(token);
		if (!mallocd_token)
		{
			/* handle malloc fail */
		}

		*tokens[*tokens_size - 1] = mallocd_token;
	}
	else
	{
		*tokens[*tokens_size - 1] = NULL;
	}

	return (*tokens);
}

/**
 * tokenize - Gets token from given string.
 *
 * @line: line to tokenize.
 *
 * Return: list of malloc'd tokens.
 */
static char **tokenize(char **line, char **tokens)
{
	size_t tokens_size;
	char *token;

	tokens_size = 0;
	token = strok(*line, " \n\t");
	while (token)
	{
		add_token_to_tokens(token, &tokens_size, &tokens);
		token = strok(NULL, " \n\t");
	}

	add_token_to_tokens(NULL, &tokens_size, &tokens);

	return (tokens);
}

/**
 * main - Main.
 *
 * @ac: n of args.
 * @av: args.
 *
 * Return: 0 if successful.
 */
int main(int ac, char **av)
{
	int i;
	char *line;
	size_t line_size;
	char **tokens;

	/* WIP, Task 22 */
	if (ac > 1)
	{
		return (0);
	}

	line = malloc(120 * sizeof(char));
	tokens = malloc(sizeof(char *));
	while (1)
	{
		printf("%s<<Shelloc Homes>> $ %s", RED, RESET);

		/* WIP, Reads line using getline */
		line = get_line(&line, &size, stdin);

		/* WIP, Tokenizes line into tokens */
		tokens = tokenize(line, tokens);

		/* WIP */
		result = shelloc(args);

		/* Frees malloc'd strings from (tokens) */
		free_tokens(tokens);

		/* exit command and error handling */
		if (result == -2)
			break;
		else if (result != 0)
			handle_error(result);
	}

	free(line);
	free(tokens);
	return (0);
}


