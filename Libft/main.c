#include        <stdio.h>
#include        <string.h>
#include        "libft.h"

int main(void)
{
        char str[] = "0123456789";
		char str2[] = "1111111";
        ft_memcpy(str + 2, str2, 5);
		printf("%s\n", str);
		/*for(int i = 0; i < 10; i++)
		{
			printf("%c\n", str[i]);
		}*/
}