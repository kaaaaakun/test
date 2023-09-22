#include <stdio.h>

int main(int argc, char *argv[], char *env[])
{
	printf("[%s]\n", env[0]);
	(void)argc;
	(void)argv;
}
