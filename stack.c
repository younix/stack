/*
 * Copyright (c) 2014 Jan Klemkow <j.klemkow@wemelug.de>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

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
