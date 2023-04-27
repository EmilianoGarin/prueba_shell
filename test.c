#include "main.h"
char **splitpath(void)
{
	char *ubi = getenv("PATH");
	char **pwd;

	if (ubi == NULL)
		exit(EXIT_FAILURE);
	pwd = split_buff(ubi, ":");
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
