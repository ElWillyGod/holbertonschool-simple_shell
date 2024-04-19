#include "main.h"

#define RED "\033[31m"
#define RESET "\033[0m"

/**
 * free_tokens - Frees the malloc'd tokens in the tokens list.
 *
 * @tokens: Malloc'd token list.
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
static char **add_token_to_tokens(char *token, size_t *tokens_size,
		char **tokens)
{
	*tokens_size += 1;
	tokens = realloc(tokens, sizeof(char *) * (*tokens_size));
	if (!tokens)
	{
		perror("Malloc fail");
		exit(1);
	}

	if (token)
	{
		tokens[*tokens_size - 1] = strdup(token);
		if (!tokens[*tokens_size - 1])
		{
			perror("Malloc fail");
			exit(2);
		}
	}
	else
	{
		tokens[*tokens_size - 1] = NULL;
	}

	return (tokens);
}

/**
 * tokenize - Gets token from given string.
 *
 * @line: Line to tokenize.
 * @tokens: Malloc'd list to save tokens.
 *
 * Return: List of malloc'd tokens.
 */
static char **tokenize(char *line, char **tokens)
{
	size_t tokens_size;
	char *token;

	tokens_size = 0;
	token = strtok(line, " \n\t");
	while (token)
	{
		tokens = add_token_to_tokens(token, &tokens_size, tokens);
		token = strtok(NULL, " \n\t");
	}

	tokens = add_token_to_tokens(NULL, &tokens_size, tokens);

	return (tokens);
}

/**
 * shelloc_file - Runs shell on the file given.
 *
 * @filename: Path to file.
 */
void shelloc_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	close(fd);
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
	char *line;
	size_t line_size;
	char **tokens;
	ssize_t result1;
	int result2;
	Tlist *path_head;

	path_head = path_in_list();
	if (ac == 2)
	{
		shelloc_file(av[1]);
		return (0);
	}
	signal(SIGINT, SIG_IGN);
	tokens = malloc(sizeof(char *));
	line = NULL;
	line_size = 0;
	while (1)
	{
		printf("%s<<Shelloc Homes>>%s $ ", RED, RESET);
		result1 = getline(&line, &line_size, stdin);
		if (result1 == -1)
			break;
		tokens = tokenize(line, tokens);
		if (_strcmp(tokens[0], "exit") == 0)
		{
			free_tokens(tokens);
			break;
		}
		result2 = execute_command(tokens, path_head);
		free_tokens(tokens);
		if (result2 == -2)
			break;
		else if (result2 != 0)
			error_handler(result2);
	}
	free_list(path_head);
	free(line);
	free(tokens);
	return (0);
}


