#include ".h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
