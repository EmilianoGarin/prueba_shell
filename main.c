#include "main.h"

void sig_handler(int signo)
{
    printf("received EXIT\n");
}


int  main(void)
{
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

		sprintf(c, "%s/%s", "/usr/bin", av[0]);
		printf("Before execve\n");
		if (execve(c, av, NULL) == -1)
			break;

		printf("After execve\n");
	}
	printf("\n");
	free(buff);
	return (0);
}
