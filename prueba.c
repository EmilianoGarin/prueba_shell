#include "main.h"
void sig_handler()
{
	printf("received EXIT\n");
}

int main(void)
{
	char *buff;
	char **av = NULL, **split_p = NULL;
	int ac = 0, status = 1;

	signal(SIGINT, sig_handler);
	do {
		printf("$ ");

		buff = buffer();
		printf("%p  %s\n", buff, buff);
		if (buff == NULL)
		{
			if(split_p != NULL)
				free_ar(split_p);
			exit(0);
		}

	
			av = split_buff(buff, " \n");
			free(buff);
			if (split_p == NULL)
				split_p = splitpath();
			if (av[0][0] == '/')
			{
				ac = access(av[0], X_OK);
				if (ac == 0)
					for_exe(av, av[0]);
			} else
			{

				find_exe(av, split_p);
			}

			free_ar(av);

	} while (status);
	printf("\n");
	return (0);
}
