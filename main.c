#include "main.h"
int main(void)
{
	char *buff;
	char *buff, name[1024];
	char **av;
	int status = 0;

	signal(SIGINT, sig_handler);
	do {
		printf("$ ");

		buff = buffer();

		av = split_buff(buff);

		sprintf(name, "%s/%s", "/usr/bin", av[0]);				
		av[0] = name;
		if (access(name, F_OK) != 0)
		{
			printf("%s: command not found\n", name);
		}
		free(buff);

		status = for_exe(av);


		free(av);
	} while (status);



	printf("\n");
}
