# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <fcntl.h>
# include <limits.h>
# include <dirent.h>

void	*expandable(char *str, int *flag)
{
	int		i;
	char	s_quote;

	i = 0;
	s_quote = 0;
	if (str[i] == '\'')
		s_quote = 1;
	while (str[i] == '\'')
		i++;
	while (str[i])
	{
		if (str[i] == '\'' && s_quote)
			s_quote = !s_quote;
		if (str[i] == '"' && !s_quote)
			return ((*flag = !(*flag)), NULL);
		i++;
	}
	return (NULL);
}

int	main()
{
	char	*str;
	int		flag;
	int		test;


	while (1)
	{
		flag = 0;
		str = readline("> ");
		test = (str[0] == '"');
		printf("test: %d\n", test);
		expandable(str, &flag);
		printf("Is expandable?? %d\n", flag);
		free(str);
	}
	return (0);
}
