#include        <stdio.h>
#include        <string.h>
#include        "libft.h"

int main(void)
{
	printf("%d\n", ft_memcmp("abcd", "abcd", 4));
	printf("%d\n", ft_memcmp("abcd", "abed", 4));
	printf("%d\n", ft_memcmp("abcd", "abad", 4));
	printf("%d\n", ft_memcmp("abcd", "abad", 0));
}