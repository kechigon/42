#include        <stdio.h>
#include        <string.h>
#include        <stdlib.h>
#include        <ctype.h>
#include        "libft.h"

int main(void)
{
	printf("%s\n",ft_strtrim("abc def\tghi", " \t"));
}