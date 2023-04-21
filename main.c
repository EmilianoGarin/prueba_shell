#include "main.h"
#include <stdlib.h>
void sig_handler(int signo)
{
	printf("received EXIT\n");
}
int  main(void)
{
	extern char **environ;
	char c[1024];
	char *buff = NULL;
	char *token;
	char *av[1024];
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
			execve(c, av, environ);
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
	return (0);
}
