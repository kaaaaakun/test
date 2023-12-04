#include <stdio.h>
#include "libft.h"

void print_data(void *data) {
    printf("%s\n", (char *)data); // int型と仮定
}

int	main(int argc,char *argv[], char *env[])
{
	int				i;
	t_libft_list	*newlist;
	t_libft_list	*envlist;

	i = 0;
	envlist = NULL;
	write (1,"a",1);
	while (env[i] != NULL)
	{
		newlist = ft_lstnew(env[i]);
		if (!newlist)
			exit (0);
		ft_lstadd_back(&envlist, newlist);
		i++;
	}
	write (1,"c\n",2);
	ft_lstiter(envlist, print_data);
	(void)argc;
	(void)argv;
	exit (0);
}
