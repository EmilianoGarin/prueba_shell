#include "main.h"


char **_recalloc(char **words, unsigned int rep)
{
	char **new_words = NULL;
	unsigned int i = 0;

	if (words == NULL)
	{
		new_words = malloc(sizeof(char *) * SIZE);
		if (new_words == NULL)
			return (NULL);
		for (i = 0; i < SIZE; i++)
			new_words[i] = NULL;
	}
	else
	{
		new_words = malloc(sizeof(char *) * SIZE * rep);
		if (new_words == NULL)
		{
			free(words);
			return (NULL);
		}
		for(i = 0; i < SIZE * (rep - 1); i++)
			new_words[i] = words[i];
		for(; i < SIZE * rep; i++)
			new_words[i] = NULL;
		free(words);
	}
	return (new_words);
}
