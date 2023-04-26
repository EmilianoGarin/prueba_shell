#include "main.h"

char *_getenv(char *name) /** ingresar "PATH" en name*/
{
    char **env = environ;
    int name_len = strlen(name);

    for (int i = 0; env[i] != NULL; i++) {
        if (strncmp(env[i], name, name_len) == 0 && env[i][name_len] == '=') {
            return &env[i][name_len + 1];
        }
    }

    return NULL;
}
