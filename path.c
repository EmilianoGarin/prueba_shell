#include "main.h"
/**
 * path - Serch for the path.
 * Return: Returns a pointer.
 */
char *path(void)
{
	char **env = environ;
	char *path;
	int i, e = 0, j = 0;

	for (i = 5; env[12][i] != '\0'; i++)
	{
		j++;
	}
	path = malloc(sizeof(char) * (j + 1));
	for (i = 5; env[12][i] != '\0'; i++)
	{
		path[e] = env[12][i];
		e++;
	}
	return (path);
}
