#include "main.h"

/**
 * separator - Separates if separators are found.
 *
 * @args: List of arguments.
 * @path_head: Head of list path.
 * @main_loop: Pointer to the boolean var of the main loop.
 */
void separator(char **args, Tlist *path_head, int *main_loop)
{
	execute_command(args, path_head, main_loop);
}


