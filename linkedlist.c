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
 * tokenize_path - Separates the PATH environment and converts it to a list
 *
 * @environe: Copy of the var PATH.
 * @separator: ss
 *
 * Return: list head;
 */
Tlist *tokenize_path(char *environe, char *separator)
{
	char *token;
	Tlist *newNode = NULL;
	Tlist *head = NULL;
	Tlist *prev = NULL;

	token = strtok(environe, separator);
	while (token)
	{
		newNode = malloc(sizeof(Tlist));
		if (!newNode)
		{
			fprintf(stderr, "Malloc fail.");
			free(environe);
			free_list(head);
			exit(20);
		}

		newNode->direct = strdup(token);
		if (!newNode->direct)
		{
			fprintf(stderr, "Malloc fail.");
			free(newNode);
			free(environe);
			free_list(head);
			exit(21);
		}

		newNode->next = NULL;
		if (prev)
			prev->next = newNode;
		else
			head = newNode;

		prev = newNode;
		token = strtok(NULL, separator);
	}
	return (head);
}


/**
 * path_in_list - Creates singly linked list of path.
 * @environe: sad
 * @separatpr: xd
 *
 * Return: Singly linked list of path.
 */
Tlist *path_in_list(char *environe, char *separatpr)
{
	char *path;
	char *path_copy;
	Tlist *head;

	path = _getenv(environe);
	if (!path)
		return (NULL);

	path_copy = _strdup(path);
	if (!path_copy)
	{
		fprintf(stderr, "Malloc error.");
		exit(19);
	}

	free(path);

	head = tokenize_path(path_copy, separatpr);

	free(path_copy);
	return (head);
}
