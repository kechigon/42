#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char **args)
{
	/*(void)argc;
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
	printf("%d\n", get_next_line(fd, res));
	printf("%s\n", *res);
	free(*res);*/
	if (argc != 2)
		return 0;
	char **res;
	char *s = NULL;
	res = &s;
	char c = args[1][0];
	int n;
	if (!args[1][1] && c == '0')
	{
		while (1)
		{
			n = get_next_line(0, res);
			if (n == -1)
			{
				printf("gnl erorr\n");
				return (1);
			}
			printf("%s\n", *res);
			if (!n)
				break;
		}
	}
	else
	{
		int fd = open(args[1], O_RDONLY);
		if (fd != -1)
		{
			while (1)
			{
				n = get_next_line(fd, res);
				if (n == -1)
				{
					printf("gnl erorr\n");
					return (1);
				}
				printf("%s\n", *res);
				if (!n)
					break;
			}
		}
		close(fd);
	}
}