#include <monty.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;  // Initialize the top of the stack to -1

void push(int value) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "L%d: can't push, stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

void pall() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
#endif
