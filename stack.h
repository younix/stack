#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>

struct cstack { size_t pointer; char stack[BUFSIZ]; };
struct istack { size_t pointer; int stack[BUFSIZ]; };
struct fstack { size_t pointer; float stack[BUFSIZ]; };
struct dstack { size_t pointer; double stack[BUFSIZ]; };

bool cstack_push(struct cstack *stack, char item);
bool cstack_pop(struct cstack *stack, char *item);

bool istack_push(struct istack *stack, int item);
bool istack_pop(struct istack *stack, int *item);

bool fstack_push(struct fstack *stack, float item);
bool fstack_pop(struct fstack *stack, float *item);

bool dstack_push(struct dstack *stack, double item);
bool dstack_pop(struct dstack *stack, double *item);

#endif
