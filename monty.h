#ifndef MAIN
#define MAIN

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct stack_s 
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


int push(stack_t **stack, char *value);
int pall(stack_t **stack);
int line_scanner(FILE **file, char **line);
int find_function(stack_t **stack, char *command, char *value);

#endif

