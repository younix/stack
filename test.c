#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"

int
main(int argc, char*argv[])
{
	struct cstack c;
	struct istack i;
	struct fstack f;
	struct dstack d;

	char   cval = '1';
	int    ival = 1;
	float  fval = 1.0;
	double dval = 1.0;

	cstack_init(&c);
	istack_init(&i);
	fstack_init(&f);
	dstack_init(&d);

	for (int p = 0; p < BUFSIZ; p++) {
		if (cstack_push(&c, cval) == false) goto err;
		if (istack_push(&i, ival) == false) goto err;
		if (fstack_push(&f, fval) == false) goto err;
		if (dstack_push(&d, dval) == false) goto err;
	}

	if (cstack_push(&c, cval) == true) goto err;
	if (istack_push(&i, ival) == true) goto err;
	if (fstack_push(&f, fval) == true) goto err;
	if (dstack_push(&d, dval) == true) goto err;

	for (int p = 0; p < BUFSIZ; p++) {
		if (cstack_pop(&c, &cval) == false) goto err;
		if (istack_pop(&i, &ival) == false) goto err;
		if (fstack_pop(&f, &fval) == false) goto err;
		if (dstack_pop(&d, &dval) == false) goto err;

		if (cstack_push(&c, cval) == false) goto err;
		if (istack_push(&i, ival) == false) goto err;
		if (fstack_push(&f, fval) == false) goto err;
		if (dstack_push(&d, dval) == false) goto err;

		if (cstack_pop(&c, NULL) == false) goto err;
		if (istack_pop(&i, NULL) == false) goto err;
		if (fstack_pop(&f, NULL) == false) goto err;
		if (dstack_pop(&d, NULL) == false) goto err;
	}

	if (cstack_pop(&c, NULL) == true) goto err;
	if (istack_pop(&i, NULL) == true) goto err;
	if (fstack_pop(&f, NULL) == true) goto err;
	if (dstack_pop(&d, NULL) == true) goto err;

	return EXIT_SUCCESS;
 err:
	return EXIT_FAILURE;
}
