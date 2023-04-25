#include "main.h"
int splitpath(char **av)
{
	char *ubi = getenv("PATH");
	char *token;
	char **pwd;
	int i, size = 0;
	int ac;

	if (ubi == NULL)
		exit(EXIT_FAILURE);
	for (i = 0; ubi[i] != '\0'; i++)
		if (ubi[i] == ':')
			ubi[i] = ' ';
	pwd = split_buff(ubi);
	for (i = 0; pwd[i] != NULL; i++)
	{
		token = NULL;
		sprintf(token, "%s/%s", pwd[i], av[0]);
		ac = access(token, X_OK);
		if (ac == 0)
		{
			av[0] = token;
			free(pwd);
			free(ubi);
			free(token);
			for_exe(av);
			return (1);
		}
	}
	perror("Invalid direction");
	free(pwd);
	free(ubi);
	free(token);
	return (1);
}
