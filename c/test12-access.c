#include <libc.h>

int	main(void)
{
	int	return_value;
	char	*test_word;

	test_word = "/bin/ls";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = "./bin/ls";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = "/../bin/ls";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = "bin/ls";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = "./../../../bin/ls";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = "../../../../../bin/ls";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = "ng-test.sh";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = "./ng-test.sh";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = "../ng-test.sh";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = ".../ng-test.sh";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = ".//ng-test.sh";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = ".///ng-test.sh";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = ".////////////////ng-test.sh";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = ".//././///.//./././//.//ng-test.sh";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = "...../ng-test.sh";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = "../ng-test.sh";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
	
	test_word = "/ng-test.sh";
	return_value = access(test_word,F_OK);
	printf("re_va : %2d | %s\n", return_value, test_word);
}
