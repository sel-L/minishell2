#include "main_minishell.h"

void	init(char **envp)
{
	t_parsing *parsing;

	if (!envp || !*envp)
		return (ft_putendl_fd("Invalid envp", 2));
	parsing = malloc(sizeof(t_parsing));
	if (!parsing)
	return (ft_putendl_fd("init: malloc failed", 2));
	parsing->env_list = env_to_list(envp);
}

int	parsing(char *str, t_parsing *parse)
{
	parse->token = tokenizer(str);
	if (validator(parse->token) != 0)
		return (free_token_list(parse->token), 1);
	parse->ast = ast(&parse->token);
	process_ast_expansion(parse->ast, parse);
	return (0);
}

int	process_input(t_parsing *parsing)
{
	char	*str;

	str = ft_readline(parsing, "> ");

}
