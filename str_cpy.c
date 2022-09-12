#include "header.h"
/**
 * str_cpy - Copies the first bytes of src in dest and set the remaining bytes
 * of dest with the null character
 * @dest: String to copy into it
 * @src: String to copy from
 * @bytes: The number of bytes to copy from src
 * Return: dest or NULL on failure
 */
char *str_cpy(char *dest, char *src, int bytes)
{
	int i = 0;

	dest = malloc(sizeof(char) * (bytes + 1));
	if (!dest)
		return (NULL);
	while (src[i])
		dest[i] = src[i], i++;
	dest[i] = '\0';
	return (dest);
}
