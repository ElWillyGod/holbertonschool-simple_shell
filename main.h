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
#include <errno.h>

extern char **environ;

#define RED "\033[31m"
#define RESET "\033[0m"
#define FAIL (-1)


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

/**
 * struct bi_s - asdfg
 *
 * @command: asdfg
 * @func: asdfg
 */
typedef struct bi_s
{
	char *command;
	void (*func)(char **, int *, char *);
} bi_t;


/* str_tools.c */
unsigned int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);

/* int_tools.c */
int _isdigit(int c);
int _atoi(char *s);

/* strtok.c */
char *_strtok(char *, char *);

/* realloc.c */
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/* linedlist.c */
void free_list(Tlist *list);
Tlist *path_in_list(char *env, char *separator);

/* get_env */
char *_getenv(const char *var);

/* built_ins.c */
int is_built_in(char **args, int *main_loop, char *shell_name);

/* execute.c */
void execute_command(char **args, Tlist *path_head, int *main_loop,
		char *shell_name);

/* separator.c */
void separator(char **tokens, Tlist *path_head, int *main_loop,
		char *shell_name);

/* error_handler.c */
void error_handler(int errnum);

/* main.c */
char **add_token_to_tokens(char *token, size_t *tokens_size, char **tokens);

#endif /* MAIN_H */

