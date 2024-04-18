#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef  struct rep_list Tlist;

extern char **environ;
extern Tlist *head;

struct rep_list
{
	char *direct;
	Tlist *next;
};

unsigned int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_utoa(char *str, unsigned int uinteger, unsigned int ulen);
char *_strdup(char *str);

size_t memory_used(void *ptr);
void *_realloc(void *ptr, size_t size);

void free_list(Tlist *list);
Tlist *path_in_list();

char *_getenv(const char *var);

char *direct_command(char *command);
int execute_command(char **args);

#endif /* MAIN_H */
