#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **args)
{
	(void)argc;
	int fd = open(args[1], O_RDONLY);
	char *str = NULL;
	char **res;
	res = &str;
	printf("%d\n", get_next_line(fd, res));
	printf("%s\n", *res);
	free(*res);
	printf("%d\n", get_next_line(fd, res));
	printf("%s\n", *res);
	free(*res);
	/*if (argc != 2)
		return 0;
	char **res;
	char *s = "";
	*res = s;
	char c = args[1][0];
	if (!args[1][1] && '0' <= c && c <= '2')
	{
		int n;
		while ((n = get_next_line(args[1][0] - '0', res)))
		{
			if (n == -1)
				printf("gnl erorr");
		}
	}
	else
	{
		int fd = open(args[1], O_RDONLY);
		if (fd != -1)
		{
			int n;
			while ((n = get_next_line(fd, res)))
			{
				if (n == -1)
					printf("gnl erorr");
			}
		}
		close(fd);
	}*/
}