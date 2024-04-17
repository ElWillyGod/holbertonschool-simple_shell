#include ".h"
#include <stdlib.h>

/**
*
*
*
*
*
*
*/

void free_list(Tlist *list)
{
	while (list)
	{
		Tlist *aux = list->next;
		free(list->direct);
		free(list);
		list = aux;
	}
}

Tlist *path_in_list()
{
	char *path = _getenv("PATH");
	if (!path)
	{
		fprintf(stderr, "Problemas con el PATH");
		exit(19);
	}
	Tlist *head = NULL;
	Tlist *prev = NULL;
	char *token;
	char *path_copy = strdup(path);
	if (!path_copy)
		fprintf(stderr, "ERROR con la copia");
	
	token = strtok(path_copy, ":");
	while (token)
	{
		Tlist *newNode = malloc(sizeof(Tlist));
		if (!newNode)
		{
			fprintf(stderr, "ya me aburri de los errores, malloc newNode");
			//free(newNode);
			free(path_copy);free_list(head);
			exit(20);
		}

		newNode->direct = strdup(token);
		if (!newNode->direct)
		{
			fprintf(stderr, "por las dudas nomas yo que se, error al copiar el token");
			free(newNode);free(path_copy);free_list(head);
			exit(21);
		}

		newNode->next = NULL;
		if (prev)
			prev->next = newNode;
		else
			head = newNode;

		prev = newNode;
		token = strtok(NULL, ":");
	}

	free(path_copy);free(path);
	return (head);
}
