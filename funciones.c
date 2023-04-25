#include "main.h"
#define BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

char *buffer(void)
{
	char *buff = NULL;
	ssize_t len = 0;

	fflush(stdin);
	if (getline(&buff, &len, stdin) == -1)
	{
		free(buff);
		printf("\n");
		exit(EXIT_FAILURE);
	}
	return (buff);
}


char **split_buff(char *buffer)
{
	int len, size = 0, posi = 0;
	char **av = NULL;
	char *token;
	char *buff;

	buff = strdup(buffer);
	if (buff == NULL)
		return (NULL);
	token = strtok(buff, " \n");
	while (token != NULL)
	{
		size++;
		token = strtok(NULL, " \n");
	}

	av = malloc(sizeof(char *) * (size + 1));
	if (av == NULL)
		exit(EXIT_FAILURE);

	token = strtok(buff, " \n");
	for (; posi < size; posi++)
	{
		av[posi] = token;
		token = strtok(NULL, " \n");
	}
	av[posi] = NULL;
	return (av);
}

int for_exe(char **av)
{
	pid_t pid = fork();
	int status;

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

