#include "main.h"
/**
 * memory_used - Gets memory used.
 *
 * @ptr: Pointer to memory.
 *
 * Return: Size of memory used.
 */
size_t memory_used(void *ptr)
{
	char *memory;
	size_t size;

	if (!ptr)
		return (0);

	memory = (char *)ptr - sizeof(size_t);
	size = *(size_t *)memory;
	size -= sizeof(size_t);

	return (size);
}

/**
* _realloc - Reallocates allocated memory.
*
* @ptr: Pointer to memory.
* @size: Size to allocate the new location.
*
* Return: Pointer to newly allocated memory.
*/

void *_realloc(void *ptr, size_t size)
{
	size_t i;
	size_t size_old;
	void *new_ptr;
	size_t size_min;

	if (!ptr)
		return (malloc(size));

	if (!size)
	{
		free(ptr);
		return (NULL);
	}

	size_old = memory_used(ptr);
	new_ptr = malloc(size);

	if (!new_ptr)
		return (NULL);

	size_min = (size < size_old) ? size : size_old;

	for (i = 0; i < size_min; i++)
		((char *)new_ptr)[i] = ((char *)ptr)[i];

	free(ptr);
	return (new_ptr);
}
