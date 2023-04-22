#include "main.h"
#define BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

char *buffer(void)
{
	char *buff = NULL;
	ssize_t len = 0;

	fflush(stdin);
	if (getline(&buff, &len, stdin) == -1)
		exit(EXIT_FAILURE);
	return (buff);
}


char **split_buff(char *buff)
{
	int len, size = 0, posi = 0;
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

	printf("%d ", size + 1);
	token = strtok(buff, " \n");
	for (; posi < size; posi++)
	{
		printf("%d ", posi);
		av[posi] = token;
		token = strtok(NULL, " \n");
	}
	printf("\n%d ", posi);
	av[posi] = NULL;
	return (av);
}

int for_exe(char **av)
{
	char c[1024];
	pid_t wpid, pid = fork();
	int status;

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
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
