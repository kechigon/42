#include        <stdio.h>
#include        <string.h>
#include        <stdlib.h>
#include        <ctype.h>
#include        "libft.h"

int main(void)
{
	void *p = malloc(3);
	printf("%p\n", p);
	free(p);
	printf("%p\n", p);
}