#include        <stdio.h>
#include        <string.h>
#include        <stdlib.h>
#include        <ctype.h>
#include        "libft.h"

int main(void)
{
	char **res = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	while (*res)
	{
		printf("%s\n", *res);
		res++;
	}
}