#include "main.h"
void free_ar(char **ar) {
    int i;
    for (i = 0; ar[i] != NULL; i++) {
        free(ar[i]);
    }
    free(ar);
}
char **_strtok(char *path)
{
        char **cortado;
        int a = 0, i, c = 0, d = 0, l, t = 0, j = 0, len = 0;
        path = "/usr/bin:/usr/local/bin:/bin/sbin";
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
int main(void) {
    char *path = "/usr/bin:/usr/local/bin:/bin/sbin";
    char **paths = _strtok(path);
    int i;
    for (i = 0; paths[i] != NULL; i++) {
        printf("Ruta %s\n", paths[i]);
    }

    // Liberar memoria asignada por _strtok
    for (i = 0; paths[i] != NULL; i++) {
       free(paths[i]);
    }
    free(paths);

    return 0;
}

~
~
~
~
