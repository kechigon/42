#include <stdio.h>
#include <stdint.h>

int main()
{
	printf("%zu\n", SIZE_MAX);
	long n = 100000 * 100000;
	printf("%ld\n", n);
}