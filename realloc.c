#include "main.h"
/**
 * _memcpy - cpies memory area
 *
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Amount of memory byte
 *
 * Return: pointer a dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}

/**
* my_realloc - Reallocates allocated memory.
*
* @ptr: Pointer to memory.
* @old_size: la antigua memoia.
* @new_size: nuevo tamanio de memory;
*
* Return: Pointer to newly allocated memory.
*/
void *my_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	if (old_size < new_size)
		_memcpy(new_ptr, ptr, old_size);

	else
		_memcpy(new_ptr, ptr, new_size);
	
	free(ptr);

	return (new_ptr);
}
