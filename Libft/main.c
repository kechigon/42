#include        <stdio.h>
#include        <string.h>
#include        "libft.h"

int main(void)
{
	char str[10] = "abcdefghi\0";

	printf("%p\n", str);
	printf("%p\n", ft_memchr(str, 'e', 2));
}