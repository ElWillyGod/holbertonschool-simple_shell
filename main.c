#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define RED "\033[31m"
#define RESET "\033[0m"

/**
 *
 */

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
	char **tokens;


	/* WIP, Task 22 */
	if (ac > 1)
	{
		return (0);
	}

	line = malloc(120 * sizeof(char));
	tokens = malloc(sizeof(char *));
	args = malloc(sizeof(char *))
	while (1)
	{
		printf("%s<<Shelloc Homes>> $ %s", RED, RESET);

		/* WIP, Reads line using getline */
		line = read_input(line);

		/* WIP, Tokenizes line into tokens */
		tokens = tokenize(line);

		/* WIP, Separates tokens if ;, then &&, then | (if any) */
		args = separate(tokens);

		/* WIP, Searches executables in builtins f pointer and path,
		 * then executes if found, error if not. */
		result = shelloc(args);

		/* exit command and error handling */
		if (result == -2)
			break;
		else if (result != 0)
			handle_error(result);
	}

	free(line);
	free(tokens);
	free(args);
	return (0);
}




