#include "main.h"

/**
* _getenv - Gets enviorment variable of name (var).
*
* @var: Name of variable.
* @envirron: Environ arg.
*
* Return: Content of variable.
*/
char *_getenv(const char *var, char **envirron)
{
	int i;
	size_t name, value_len;
	char *ptr;
	char *value;

	for (i = 0; envirron[i]; i++)
	{
		ptr = strchr(environ[i], '=');
		if (!ptr)
			return (NULL);

		name = ptr - environ[i];

		if (strncmp(environ[i], var, name) == 0)
		{
			value_len = strlen(ptr + 1);
			value =  malloc(value_len + 1);
			if (!value)
			{
				return (NULL);
			}

			strncpy(value, ptr + 1, value_len + 1);

			return (value);
		}
	}

	return (NULL);
}
