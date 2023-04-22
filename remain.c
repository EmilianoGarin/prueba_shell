#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include<signal.h>
#include <sys/wait.h>
#define SIZE 1024

void sig_handler(int signo)
{
	printf("received EXIT\n");
}

void *my_realloc(void *ptr, size_t size)
{
	char **p = ptr;
	char **newp = NULL;
	int i;

	if (ptr == NULL)
	{
		return malloc(size);
	}
	else if (size == 0)
	{
		free(ptr);
		return NULL;
	}
	else
	{
		newp = malloc(size);
		if (newp == NULL)
		{
			return NULL;
		}

		for (i = 0; p[i] != NULL; i++)
		{
			newp[i] = p[i];
		}
		newp[i] = NULL;

		free(p);
		return newp;
	}
}

int  main(void)
{
	char c[1024];
	char *buff = NULL;
	char *token;
	char **av = NULL;
	int i = 0, x = 0;
	size_t len = 0;
	ssize_t read = 0;

	signal(SIGINT, sig_handler);

	while(1)
	{
		printf("$ ");
		read = getline(&buff, &len, stdin);
		if (read == -1)
			break;
		token = strtok(buff, " \n");
		while (token != NULL)
		{
			if (i == x)
			{
				x += 10;
				av = my_realloc(av, sizeof(char *) * (x + 1));
				if (av == NULL)
				{
					perror("my_realloc failed");
					exit(EXIT_FAILURE);
				}
				memset(av + i, 0, sizeof(char *) * (x + 1 - i));
			}
			av[i] = token;
			printf("%s\n", av[i]);
			i++;
			token = strtok(NULL, " \n");
		}
		av[i] = NULL;
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			sprintf(c, "%s/%s", "/usr/bin", av[0]);
			execve(c, av, NULL);
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			i = 0;
		}
	}
	printf("\n");
	free(buff);
	free(av);
	return (0);
}

