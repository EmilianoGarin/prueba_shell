#include "main.h"
char **splitpath(void)
{
	char *path = _getenv("PATH");
	char **cortado = NULL;
        int a = 0, i, c = 0, d = 0, l, t = 0, j = 0, len = 0;
        len = strlen(path);
        printf("largo de la string:%d\n", len);
        for (i = 0; path[i]!= '\0'; i++)
        {
                if (path[i] == ':')
                {
                        a++;
                }
        }
        a = a + 2;
        printf("largo de la string:%d\n", a);
        cortado = (char **)malloc(a * sizeof(char *));

        if (cortado == NULL)
        {
                return NULL;
        }
        cortado[a] = NULL;
        for (i = 0; i <= len; i++)
        {
                c++;
                if (path[i] == ':' || path[i] == '\0')
                {
                        cortado[d] = (char *)malloc((c) * sizeof(char));
                        printf("largo de la palabra:%d\n", c);
                        c = 0;
                        if (cortado[d] == NULL)
                        {
                                free_ar(cortado);
                                exit(0);
                        }
                        d++;
                }
        }
        j = 0;
        t = 0;
        for (l = 0; l < len; l++)
        {
                cortado[t][j] = path[l];
                j++;
                if (path[l] == ':')
                {
                        j = 0;
                        t++;
                }
        }
        j = 0;
        t = 0;
        for (l = 0; l <= len; l++)
        {
                j++;
                if (path[l] == ':' || path[l] == '\0')
                {
                        printf("punto de la string; %d\n", t);
                        cortado[t][j - 1] = '\0';
                        t++;
                        printf("punto de la array; %d\n", j);
                        j = 0;
                }
        }
        for (i = 0; cortado[i] != NULL; i++)
                 printf("Rutia %s\n", cortado[i]);
        return (cortado);
}

	


int find_exe(char **av, char**pwd)
{
	int ac, i = 0;
	char *token = NULL;

	if (strcmp(av[0], "exit") == 0)
	{
		free_ar(pwd);
		free_ar(av);
		exit(0);
	}
	while ( pwd[i] != NULL)
	{
		token = malloc(strlen(pwd[i]) + strlen(av[0]) + 2);
		if (token == NULL)
		{
			free(pwd);
			return (1);
		}
		sprintf(token, "%s/%s", pwd[i], av[0]);
		ac = access(token, X_OK);
		if (ac == 0)
		{
			for_exe(av, token);
			free(token);
			return (1);
		}
		free(token);
		i++;
		token = NULL;
	}

}
