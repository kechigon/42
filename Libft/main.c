#include        <stdio.h>
#include        <string.h>
#include        "libft.h"

int main(void)
{
	char *s = "abcdefg";
	char *s2 = "hijklmnop";
	printf("%d\n", strlcat(s2, s, 17));
}