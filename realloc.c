#include ".h"
#include <stdlib.h>
#include <sys/types.h>

/**
 *
 *
 *
 *
 *
 *
 */

size_t memory_used(void *ptr)
{
	if (!ptr)
		return (0);

	char *memory = (char *)ptr - sizeof(size_t);
	size_t size = *(size_t *)memory;
	size -= sizeof(size_t);

	return (size);
}

/**
*
*
*
*
*
*/

void *_realloc(void *ptr, size_t size)
{
	if (!ptr)
		return malloc(size);

	if (!size)
	{
		free(ptr);
		return (NULL);
	}

	size_t i;
	size_t size_old = memory_used(ptr);
	void *new_ptr = malloc(size);

	if (!new_ptr)
		return (NULL);

	size_t size_min = (size < size_old) ? size : size_old;

	for (i = 0; i < size_min; i++)
		((char *)new_ptr)[i] = ((char *)ptr)[i];

	free(ptr);
	return (new_ptr);
}
