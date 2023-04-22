#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include<signal.h>
#include <sys/wait.h>
#define SIZE 1024



char *buffer(void);
char **split_buff(char *buff);
int for_exe(char **av);


