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
* execute_command - Executes a command.
*
* @args: List of arguments.
* @path_head: Head of list path.
*
* Return: something
*/

int execute_command(char **args, Tlist *path_head)
{
	pid_t pid;
	int status;
	char *command = args[0];

	command = _strdup(args[0]);
	if (!command)
	{
		perror("Malloc error");
		return (423);
	}

	if (command[0] != '/' && command[0] != '.')
	{
		command = direct_command(command, path_head);
		args[0] = command;
	}

	if (command || (access(command, X_OK) == 1))
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Fork error.");
			free(command);
			return (12400);
		}
		if (pid == 0)
			execve(command, args, environ);
		else
			wait(&status);
	}
	else
	{
		perror("Command not found. Burro.");
	}

	free(command);
	return (0);
}
