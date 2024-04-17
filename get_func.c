#include ".h"
#include <stdlib.h>
#include <string.h>

/**
*
*
*
*
*
*/

char *_getenv(const char *var)
{
	int i;
	size_t name, value_len;

	for (i = 0; environ[i]; i++)
	{
		char *ptr = strchr(environ[i], '=');
		if (!ptr)
			return (NULL);

		name = ptr - environ[i];

		if(strncmp(environ[i], var, name) == 0)
		{
			value_len = strlen(ptr + 1);
			char *value =  malloc(value_len + 1);
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
