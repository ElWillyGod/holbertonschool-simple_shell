#include "main.h"
/**
*
*
*
*
*
*
*/

char *direct_command(char *command)
{
	Tlist *head = path_in_list();

	if (!head)
		return (NULL);

	Tlist *current = head;

	while (current)
	{
		char aux[1024];
		sprintf(aux, "%s/%s", current->direct, command);
		if (access(aux, X_OK) == 0)
		{
			free_list(head);
			return strdup(aux);
		}
		current = current->next;
	}

	free_list(head);
	return (NULL);
}

/**
*
*
*
*
*
*
*
*/

int execute_command(char **args)
{
	pid_t pid;
	int flag = 0, status;
	char *command = args[0];
	
	if (command[0] != '/' && command[0] != '.')
	{
		flag = 1;
		command = direct_command(command);
	}

	if (command || (access(command, X_OK) == 1))
	{
		pid = fork();
		if (pid == -1)
		{
			if (flag)
				free(command);
			perror("error en el fork :(");
			return (12400);
		}
		if (pid == 0)
			execve(command, args, environ); /* ? que pasara */
		else
			wait(&status);
	}
	else
		perror("el comando no esta en el path burro, consulte help para ver comandos");

	if (flag)
		free(command);

	return (0);
}
