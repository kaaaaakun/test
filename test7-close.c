#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int	fd;
	int	fd2;

	fd = open("a.out", O_RDONLY);
	fd2 = open("test7-close.c", O_RDONLY);
	close(fd2);
	close(fd);
	return (0);
}
