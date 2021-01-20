#include        <stdio.h>
#include        <string.h>
#include        "libft.h"

int main(void)
{
    int len;
	char *str1 = "bbcdefg";
	char str2[10] = "aaaaaa";

	printf("%s\n", (char *)ft_memccpy(str2, str1, 'd', 5));

	str2[4] = '\0';
	printf("%s\n", str2);
		/*for(int i = 0; i < 10; i++)
		{
			printf("%d\n", str[i]);
		}*/
}