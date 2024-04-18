#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


extern char **environ;

typedef  struct rep_list Tlist;

struct rep_list
{
	char *direct;
	Tlist *next;
};

size_t memory_used(void *ptr);
void *_realloc(void *ptr, size_t size);

void free_list(Tlist *list);
Tlist *path_in_list();

char *_getenv(const char *var);

char *direct_command(char *command);
int execute_command(char **args);

#endif /* MAIN_H */
