#include "main.h"
void sig_handler(int signo)
{
	        printf("received EXIT\n");
}

int main(void)
{
	char *buff, name[1024];
	char **av;
	int status = 0;

	signal(SIGINT, sig_handler);
	do {
		printf("$ ");

		buff = buffer();

		av = split_buff(buff);
					
		free(buff);
		status = splitpath(av);

		free(av);
	} while (status);



	printf("\n");

}
