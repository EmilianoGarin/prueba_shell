#include "main.h"
void sig_handler()
{
	printf("received EXIT\n");
}

int main(void)
{
	char *buff;
	char **av;
	int status = 0;

	signal(SIGINT, sig_handler);
	do {
		printf("$ ");

		buff = buffer();

		av = split_buff(buff);
					
		status = splitpath(av);

//		free_ar(av, (sizeof(av) / sizeof(char *)) - 1);
		free(av);
		free(buff);
	} while (status);

	printf("\n");
	return (0);
}
