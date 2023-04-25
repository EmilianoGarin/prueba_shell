#include "main.h"
char *path(char **av)
{
	int i, e;
	char *path;
	
	for (i = 0; av[0][i] != '\0'; i++)
	{
		if (av[0][i] == '/')
		{
			corte == i
		}
	}
	for (e = 0; e < corte; e++)
	{
		pat= av[0][e]
	}
	return(path);
}
char *fusionubi(void)
{
	char *ubi;
	char ubi1[] = "/home/julien/bin:/home/julien/.local/bin:";
	char ubi2[] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:";
	char ubi3[] = "/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:";
	
	ubi = ubi1 + ubi2 + ubi3;
	return (ubi);
}


char **splitubi(char *ubi)
{
	char *token
	char **pwd
	int i, size = 0;
	
	while (i = 0; ubi[i] != '\0'; i++)
	{
		if (ubi[i] == ":")
		{
			ubi[i] = " ";
		}
	}
	token = strtok(ubi, " \n");
	while (token != NULL)
	{
		size++;
		token = strtok(NULL, " \n");
	}
	pwd = malloc(sizeof(char *) * (size + 1));
	if (av == NULL)
		exit(EXIT_FAILURE);
	token = strtok(ubi, " \n");
	for (i = 0; i < size; i++)
	{
		pwd[i] = token;
		token = strtok(NULL, " \n");
	}
	pwd[i] = NULL;
	return (pwd);
}

