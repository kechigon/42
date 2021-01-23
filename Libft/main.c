#include        <stdio.h>
#include        <string.h>
#include        "libft.h"

int main(void)
{
	char *s = "abcdefg";
	char *s2 = "hijklmnop";
	ft_strlcpy(s, s2, sizeof(s));
	printf("%s\n", s);
}