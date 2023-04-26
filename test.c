#include "main.h"
int splitpath(char **av)
{
	char *ubi = getenv("PATH");
	char *token, *buff = av[0];
	char **pwd;
	int i = 0;
	int ac;

	if (ubi == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; ubi[i] != '\0'; i++)
		if (ubi[i] == ':')
			ubi[i] = ' ';
	pwd = split_buff(ubi);
	for (i = 0; pwd[i] != NULL; i++)
	{
		token = malloc(sizeof(pwd[i]) + sizeof(av[0]) + 1);
		if (token == NULL)
		{
			free(ubi);
			free(pwd);
			return (1);
		}
		sprintf(token, "%s/%s", pwd[i], av[0]);
		ac = access(token, X_OK);
		if (ac == 0)
		{
			free(buff);
			av[0] = token;
			for_exe(av);
			return (1);
		}
		free(token);
	}
	perror("Invalid direction");
	free(pwd);
	free(token);
	return (1);
}
