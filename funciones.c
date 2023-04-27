#include "main.h"
#define BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

void free_ar(char ** av)
{
	int x;

	for (x = 0; av[x] != NULL; x++)
	{
		printf("pr f    %s  %p\n", av[x] , av[x]);
		free(av[x]);
	}
	free(av);
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
		return (NULL);
	}
	return (buff);
}

char **split_buff(char *buff, char *spliter)
{
	int size = 0, posi = 0;
	char **av = NULL;
	char *token, *cpbuff = strdup(buff);


	if (cpbuff == NULL)
		exit(0);
	token = strtok(buff, spliter);
	while (token != NULL)
	{
		size++;
		token = strtok(NULL, spliter);
	}

	av = malloc(sizeof(char *) * (size + 1));
	if (av == NULL)
		exit(EXIT_FAILURE);
	printf("   %d\n", size);

	token = strtok(cpbuff, spliter);
	for (; posi < size; posi++)
	{
		printf("  %p\n", token);
		av[posi] = strdup(token);
		printf("    %s  %p\n", av[posi] , av[posi]);
		if (av[posi] == NULL)
		{
			free_ar(av);
			free(buff);
			exit(0);
		}
		token = strtok(NULL, spliter);
	}
	av[posi] = NULL;
	free(cpbuff);
	return (av);
}

int for_exe(char **av, char *dir)
{
	pid_t pid = fork();
	

	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		printf("%s, %s", dir, av[0]);
		execve(dir, av, NULL);
		perror("execve failed");
		free_ar(av);
		exit(EXIT_FAILURE);

	}
	else
	{
		wait(NULL);
	}
	return (1);
}

