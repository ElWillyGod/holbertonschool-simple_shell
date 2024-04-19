#include "main.h"


/**
* direct_command - Finds if in path and then executes.
*
* @command: Command to test.
* @path_head: Head to list of path.
*
* Return: something.
*/
char *direct_command(char *command, Tlist *path_head)
{
	Tlist *current;
	char aux[1024];

	current = path_head;
	if (!current)
		return (NULL);

	while (current)
	{
		sprintf(aux, "%s/%s", current->direct, command);
		if (access(aux, X_OK) == 0)
		{
			return (strdup(aux));
		}
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
int run_program(char *path, char **av)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (-1);
	}

	if (child_pid == 0)
		execve(path, av, environ);
	else
		wait(&status);

	return (0);
}

/**
* execute_command - Executes a command.
*
* @args: List of arguments.
* @path_head: Head of list path.
*
* Return: something
*/
int execute_command(char **args, Tlist *path_head)
{
	char *command;
	char *first_arg;

	first_arg = args[0];
	if (!first_arg)
	{
		perror("Malloc error");
		return (423);
	}

	if (access(first_arg, X_OK) == 1)
	{
		run_program(first_arg, args);
		return (0);
	}

	command = direct_command(first_arg, path_head);

	if (command)
		run_program(command, args);
	else
		perror("Command not found. Burro.");

	free(command);
	return (0);
}
