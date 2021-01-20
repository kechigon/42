#include        <stdio.h>
#include        <string.h>
#include        "libft.h"

int main(void)
{
	char str[10] = "abcdefghi\0";

	printf("%p\n", str);
	ft_memmove(str, str, 3);
	printf("%s\n", str);
}