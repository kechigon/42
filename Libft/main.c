#include        <stdio.h>
#include        <string.h>
#include        "libft.h"

int main(void)
{
        char str[] = "0123456789";
        
        ft_memset(str+2, '*', 5);
        
        printf("%s\n",str);

        return 0;
}