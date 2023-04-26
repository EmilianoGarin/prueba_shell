#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include<signal.h>
#include <sys/wait.h>

#define SIZE 1024

extern char **environ;

char *buffer(void);
char **split_buff(char *buff);
int for_exe(char **av);
int splitpath(char **av);
void free_ar(char ** av, int i);
char *_getenv(char *name);
int main(void);
