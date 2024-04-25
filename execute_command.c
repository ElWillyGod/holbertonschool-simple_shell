#include "main.h"
#include <stdlib.h>

/**
* direct_command - Finds if in path and then executes.
*
* @command: Command to test.
* @path_head: Head to list of path.
*
* Return: something.
*/
static char *direct_command(char *command, Tlist *path_head)
{
	Tlist *current;
	char *aux;

	current = path_head;

	while (current)
	{
		aux = malloc(_strlen(current->direct) + _strlen(command) + 2);
		sprintf(aux, "%s/%s", current->direct, command);

		if (access(aux, X_OK) == 0)
		{
			return (aux);
		}

		free(aux);
		current = current->next;
	}

	return (NULL);
}

/**
 * run_program - Runs a found program.
 *
 * @path: path
 * @av: args.
 *
 * Return: int
 */

static void run_program(char *path, char **av)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Unable to fork");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(path, av, environ) == -1)
		{
			perror("execve fail");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
* execute_command - Executes a command.
*
* @args: List of arguments.
* @path_head: Head of list path.
* @main_loop: Pointer to the boolean var of the main loop.
*/

void execute_command(char **args, Tlist *path_head, int *main_loop)
{
	char *command;
	char *first_arg;

	if (!args || !args[0])
		return;

	/* Check if built-in */
	if (is_built_in(args, main_loop))
		return;

	first_arg = args[0];

	/* Check if executable */
	if (strchr(first_arg, '/'))
	{
		if (access(first_arg, X_OK) == 0)
		{
			run_program(first_arg, args);
			return;
		}
		perror(first_arg);
		return;
	}

	/* Check in PATH if executable 
	* aca tiene que haber magia*/

	command = direct_command(first_arg, path_head);
	if (command)
		run_program(command, args);
	else
		perror(first_arg);
	free(command);
}
