#include "main.h"
void sig_handler(int signo)
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
		printf("%p\n", buff );
		av = split_buff(buff);
		printf("%p\n", buff );
		printf("%p\n",av );
		printf("%p\n", *av );
		status = for_exe(av);
		printf("%p\n", buff );
		printf("%p\n",av  );
		printf("%p\n", *av );

		free(buff);
		free(av);
	} while (status);
	printf("\n");

}
