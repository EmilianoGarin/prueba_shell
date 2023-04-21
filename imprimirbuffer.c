#include "main.h"
int string(void)
{
	char **buff[1024], **token;

	getline(buff, 1024, stdin);
	token = strtok(buff," ");
	printf("%s\n", token);
	return (0);
}
