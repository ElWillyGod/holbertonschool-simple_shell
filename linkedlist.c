#include "main.h"

/**
* free_list - Frees a list.
*
* @list: List to free.
*/
void free_list(Tlist *list)
{
	Tlist *aux;

	while (list)
	{
		aux = list->next;
		free(list->direct);
		free(list);
		list = aux;
	}
}
/**
 * tokenize_path - Tokenizes and adds to list the PATH env var.
 *
 * @path_copy: Copy of the var PATH.
 *
 * Return: (head).
 */
Tlist *tokenize_path(char *path_copy)
{
	char *token;
	Tlist *newNode = NULL;
	Tlist *head = NULL;
	Tlist *prev = NULL;

	token = strtok(path_copy, ":");
	while (token)
	{
		newNode = malloc(sizeof(Tlist));
		if (!newNode)
		{
			fprintf(stderr, "Malloc fail.");
			free(path_copy);
			free_list(head);
			exit(20);
		}

		newNode->direct = strdup(token);
		if (!newNode->direct)
		{
			fprintf(stderr, "Malloc fail.");
			free(newNode);
			free(path_copy);
			free_list(head);
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
	return (head);
}


/**
 * path_in_list - Creates singly linked list of path.
 *
 * Return: Singly linked list of path.
 */
Tlist *path_in_list(void)
{
	char *path;
	char *path_copy;
	Tlist *head;

	path = _getenv("PATH");
	if (!path)
	{
		fprintf(stderr, "PATH not found.");
		exit(19);
	}

	path_copy = _strdup(path);
	if (!path_copy)
	{
		fprintf(stderr, "Malloc error.");
		exit(20);
	}

	free(path);

	head = tokenize_path(path_copy);

	free(path_copy);
	return (head);
}
