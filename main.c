#include "main.h"
#include <errno.h>
#include <signal.h>
#include <stdlib.h>

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
char **add_token_to_tokens(char *token, size_t *tokens_size,
		char **tokens)
{
	*tokens_size += 1;
	tokens = _realloc(tokens, (*tokens_size - 1) * sizeof(char *),
			*tokens_size * sizeof(char *));
	if (!tokens)
	{
		perror("Malloc fail");
		exit(EXIT_FAILURE);
	}

	if (token)
	{
		tokens[*tokens_size - 1] = strdup(token);
		if (!tokens[*tokens_size - 1])
		{
			perror("Malloc fail");
			exit(EXIT_FAILURE);
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
 * @separators: asdfg
 *
 * Return: List of malloc'd tokens.
 */
static char **tokenize(char *line, char **tokens, char *separators)
{
	size_t tokens_size;
	char *token;

	tokens_size = 0;
	if (!line)
	{
		tokens = add_token_to_tokens(NULL, &tokens_size, tokens);
		return (tokens);
	}
	token = strtok(line, separators);
	while (token)
	{
		tokens = add_token_to_tokens(token, &tokens_size, tokens);
		token = strtok(NULL, separators);
	}

	tokens = add_token_to_tokens(NULL, &tokens_size, tokens);
	return (tokens);
}

/**
 * shelloc_file - Runs shell on the file given.
 *
 * @filename: Path to file.
 *
 * Return: 0.
 */
static int shelloc_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	close(fd);

	return (errno);
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
	char *line = NULL;
	size_t line_size = 0;
	char **tokens;
	Tlist *path_head = NULL;
	int main_loop = 1, piper = 0;

	path_head = path_in_list("PATH", ":");

	if (ac == 2)
		return (shelloc_file(av[1]));
	if (!isatty(stdin->_fileno))
		piper = 1;
	errno = 0;
	signal(SIGINT, SIG_IGN);
	tokens = malloc(sizeof(char *));
	if (piper)
	{
		while (getline(&line, &line_size, stdin) > 0 && main_loop)
		{
			tokens = tokenize(line, tokens, " \t\n");
			execute_command(tokens, path_head, &main_loop);
			free_tokens(tokens);
		}
	}
	else
	{
		do {
			printf("%s<<Shelloc Homes>>%s $ ", RED, RESET);
			getline(&line, &line_size, stdin);
			tokens = tokenize(line, tokens, " \t\n");
			execute_command(tokens, path_head, &main_loop);
			free_tokens(tokens);
		} while (main_loop);
	}

	free_list(path_head), free(line), free(tokens);
	exit(errno);
}

