#include <stdio.h>

#include "stack.h"

int
main(int argc, char*argv[])
{
	struct cstack c;
	char tmp;

	c.pointer = 0;

	cstack_push(&c, 'a');
	cstack_pop(&c, &tmp);

	printf("tmp: %c\n", tmp);

	return 0;
}
