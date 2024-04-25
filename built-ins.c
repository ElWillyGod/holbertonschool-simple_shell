#include "main.h"
#include <stdio.h>
#include <sys/cdefs.h>
#include <unistd.h>

/* Built ins should have args and main_loop as arguments, and be void*/

/**
 * exit_main - Exits the shell.
 *
 * @args: List of arguments.
 * @main_loop: Pointer to the boolean var of the main loop.
 */
void exit_main(char **args, int *main_loop)
{
	int i;

	*main_loop = 0;

	if (args[1])
	{
		for (i = 0; args[1][i]; i++)
		{
			if (!_isdigit(args[1][i]))
				return;
		}
		errno = _atoi(args[1]);
	}
}

/**
 * cd - Changes CWD.
 *
 * @args: List of arguments.
 * @main_loop: Pointer to the boolean var of the main loop.
 */
void cd(char **args, __attribute__((unused)) int *main_loop)
{
	char *rute;

	if (args[1])
	{
		printf("%s\n", args[1]);

		if (chdir(args[1]) != 0)
			perror("no such file or directory");
	}
	else
	{
		rute = _getenv("HOME");
		rute ? chdir(rute), (void)printf("~\n") : perror("no tiene HOME??");
		free(rute);
	}
}

/**
 *print_env - imprime las variables de entorno
 *
 *@args: void;
 *@main_loop: void tambien;
 *
 *Return: void solo imprime;
 */

void print_env(__attribute__((unused)) char **args,
	       __attribute__((unused)) int *main_loop)
{
	/* print event*/
	int i;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);

}

/**
 * is_built_in - Checks if command is a built-in
 *
 * @args: List of arguments.
 * @main_loop: Pointer to the boolean var of the main loop.
 *
 * Return: 0 if not built-in was found, execute and ret 1 if found.
 */
int is_built_in(char **args, int *main_loop)
{
	bi_t built_ins[] = {
		{"exit", exit_main},
		{"cd", cd},
		{"env", print_env},
		{NULL, NULL}
	};
	int i;

	for (i = 0; built_ins[i].func; i++)
	{
		if (_strcmp(built_ins[i].command, args[0]) == 0)
		{
			built_ins[i].func(args, main_loop);
			return (1);
		}
	}

	return (0);
}

