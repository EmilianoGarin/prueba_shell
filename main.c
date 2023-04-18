#include "main.h"
int  main(void)
{
	char *buff;
	char *token;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	read = getline(&buff, &len, stdin);
	if (read == -1)
		return (1);
	token = strtok(buff, " ");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	free(buff);
	return (0);
}
