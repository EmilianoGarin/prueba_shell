#include "main.h"
#define BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

void free_ar(char ** av, int i)
{
	int x;

	for (x = 0; x < i; x++)
		free(av[x]);
}

char *buffer(void)
{
	char *buff = NULL;
	size_t len = 0;

	fflush(stdin);
	if (getline(&buff, &len, stdin) == -1)
	{
		free(buff);
		printf("\n");
		exit(EXIT_FAILURE);
	}
	return (buff);
}


char **split_buff(char *buff)
{
	int  size = 0, posi = 0;
	char **av = NULL;
	char *token;

	token = strtok(buff, " \n");
	while (token != NULL)
	{
		size++;
		token = strtok(NULL, " \n");
	}

	av = malloc(sizeof(char *) * (size + 1));
	if (av == NULL)
		exit(EXIT_FAILURE);

	av[0] = strtok(buff, " \n");
	if (av[0] == NULL)
	{
		free(av);
		return (NULL);
	}
	for (; posi < size; posi++)
	{
		av[posi] = strtok(NULL, " \n");

		if (av[posi] == NULL)
		{
	//		free_ar(av, posi);
			free(av);
			return (NULL);
		}
	}
	av[posi] = NULL;
		
	return (av);
}

int for_exe(char **av)
{
	pid_t pid = fork();


	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execve(av[0], av, NULL);
		perror("execve failed");
		free(av);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	return (1);
}

