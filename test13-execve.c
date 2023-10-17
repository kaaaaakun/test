#include <libc.h>

int	main(void)
{
	int		pid;
	int		i;
	int		return_value;
	char	*test_double_ptr[3];

	test_double_ptr[0] = "aaa";
	test_double_ptr[2] = NULL;
	
	char	*test_word[100] = {"/bin/echo","./bin/echo", "bin/echo", \
	"//////bin/echo", "/....//bin/echo", \
	"//././/./bin/echo", "/..//bin/echo", \
	"", "", \
	"", "======================================", \
	".ok_testdir", ".ng_testdir", \
	"/ok_testdir", "/ng_testdir", \
	"./ok_testdir", "./ng_testdir", \
	".////////////ok_testdir", ".////////ng_testdir", \
	"", "======================================", \
	"ls", "aaa", \
	"ng-test.sh", "ok-test.sh", \
	"./ng-test.sh", "./ok-test.sh", \
	"/ok-test.sh", "/ng-test.sh", \
	"../ng-test.sh", "../ok-test.sh", \
	".//ng-test.sh", ".//ok-test.sh", \
	".ng-test.sh", ".ok-test.sh", \
	"././././././///./ng-test.sh", "./././././././///./ok-test.sh", \
	"././././././///.ng-test.sh", "./././././././///.ok-test.sh", \
	NULL};

	i = 0;
	while(test_word[i] != NULL)
	{
		printf("F_OK%2d| X_OK%2d| %s\n", access(test_word[i], F_OK), access(test_word[i], X_OK), test_word[i]);
		test_double_ptr[1] = test_word[i];
		usleep(100);
		pid = fork();
		if (pid == 0)
		{
			execve(test_word[i], test_double_ptr, NULL);
			write(1,"	",1);
			perror(NULL);
			exit (0);
		}
		wait(NULL);
		i++;
	}
}
