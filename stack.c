#include "stack.h"

bool
#if STACK_CHAR
cstack_push(struct cstack *stack, char item)
#elif STACK_INT
istack_push(struct cstack *stack, int item)
#elif STACK_FLOAT
fstack_push(struct cstack *stack, float item)
#elif STACK_DOUBLE
dstack_push(struct cstack *stack, double item)
#endif
{
	if (stack->pointer >= BUFSIZ)
		return false;

	stack->stack[stack->pointer++] = item;

	return true;
}

bool
#if STACK_CHAR
cstack_pop(struct cstack *stack, char *item)
#elif STACK_INT
istack_pop(struct istack *stack, char *item)
#elif STACK_FLOAT
fstack_pop(struct fstack *stack, char *item)
#elif STACK_DOUBLE
dstack_pop(struct dstack *stack, char *item)
#endif
{
	if (stack->pointer == 0)
		return false;

	*item = stack->stack[--(stack->pointer)];

	return true;
}
