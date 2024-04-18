#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

extern char **environ;

/**
 * struct rep_list - Singly linked list's node of path.
 *
 * @direct: Content.
 * @next: Pointer to next node.
 */
typedef struct rep_list
{
	char *direct;
	struct rep_list *next;
} Tlist;

unsigned int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_utoa(char *str, unsigned int uinteger, unsigned int ulen);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

size_t memory_used(void *ptr);
void *_realloc(void *ptr, size_t size);

void free_list(Tlist *list);
Tlist *path_in_list();

char *_getenv(const char *var);

char *direct_command(char *command, Tlist *path_list);
int execute_command(char **args, Tlist *path_list);

void error_handler(int errno);

extern Tlist *head;

#endif /* MAIN_H */

