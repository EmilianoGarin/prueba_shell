#include "main.h"
char **splitpath(void)
{
	char *token, *ubi = getenv("PATH");
	char **pwd;
	int x = 0, j = 0, i = 0, size = 0;

	if (ubi == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; ubi[i] != '\0'; i++)
		if (ubi[i] == ':')
			size++;

	pwd = malloc(sizeof(char*) * (size + 1));
	if (pwd == NULL)
		exit(0);

	printf("%d \n", size);
	pwd[0] = strdup(strtok(ubi, ":"));
	
	printf("%s   %p \n", pwd[0], pwd[0]);
	for (i = 1; i < size; i++)
	{
		pwd[i] = strdup(strtok(NULL, ":"));
		
		printf("%s   %p \n", pwd[i], pwd[i]);
	}
	pwd[++i] = NULL;
	printf("%d \n", i);
	
	/*	for (i = 0; ubi[i] != '\0'; i++)
	{
		j++;
		if (ubi[i] == ':')
		{
			ubi[i] = '\0';
			pwd[x][j] = ubi[i];
			j = 0;
			x++;
		}
		else
			pwd[x][j] = ubi[i];
	}
	pwd[x][j + 1] = '\0';
	pwd[x + 1] = NULL;
*/
	return (pwd);
}

int find_exe(char **av, char**pwd)
{
	int ac, i = 0;
	char *token = NULL;

	if (strcmp(av[0], "exit") == 0)
	{
		free_ar(pwd);
		free_ar(av);
		exit(0);
	}
	while ( pwd[i] != NULL)
	{
		token = malloc(strlen(pwd[i]) + strlen(av[0]) + 1);
		if (token == NULL)
		{
			free(pwd);
			return (1);
		}
		sprintf(token, "%s/%s", pwd[i], av[0]);
		printf("%s || %ld || %ld || %ld\n", token, strlen(token), strlen(pwd[i]), strlen(av[0]));
		ac = access(token, X_OK);
		if (ac == 0)
		{
			for_exe(av, token);
			free(token);
			return (1);
		}
		free(token);
		i++;
	}

}
