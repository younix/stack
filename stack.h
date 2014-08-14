/*
 * Copyright (c) Jan Klemkow <j.klemkow@wemelug.de>
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

#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stdio.h>

struct cstack { size_t pointer; char stack[BUFSIZ]; };
struct istack { size_t pointer; int stack[BUFSIZ]; };
struct fstack { size_t pointer; float stack[BUFSIZ]; };
struct dstack { size_t pointer; double stack[BUFSIZ]; };

void cstack_init(struct cstack *stack);
bool cstack_push(struct cstack *stack, char item);
bool cstack_pop(struct cstack *stack, char *item);

void istack_init(struct istack *stack);
bool istack_push(struct istack *stack, int item);
bool istack_pop(struct istack *stack, int *item);

void fstack_init(struct fstack *stack);
bool fstack_push(struct fstack *stack, float item);
bool fstack_pop(struct fstack *stack, float *item);

void dstack_init(struct dstack *stack);
bool dstack_push(struct dstack *stack, double item);
bool dstack_pop(struct dstack *stack, double *item);

#endif
