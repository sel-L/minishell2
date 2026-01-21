/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:21 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/21 19:14:42 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/parsing.h"
#include "main_minishell.h"

int	g_signal = 0;

t_parsing	*init(char **envp)
{
	t_parsing	*parse;
	char		*temp;

	//Initialize parsing struct with envp
	if (!envp)
		return (ft_putendl_fd("init: no env\n", 2), NULL);
	parse = malloc(sizeof(t_parsing));
	if (!parse)
		return (ft_putendl_fd("init: malloc failed\n", 2), NULL);
	ft_bzero(parse, sizeof(t_parsing));
	parse->interactive_mode = isatty(STDIN_FILENO) && isatty(STDERR_FILENO);
	parse->env_list = env_to_list(envp);
	if (!parse->env_list)
		return (free(parse), ft_putendl_fd("init: env error\n", 2), NULL);
	parse->internal_env = NULL;
	if (ft_atoi(getenv("SHLVL")) >= 0)
	{
		temp =  ft_itoa(ft_atoi(getenv("SHLVL")) + 1);
		change_key_value("SHLVL", temp, &parse->env_list);
		free(temp);
	}
	return (parse);
}

int	process_command(t_parsing *p)
{
	char	**envp;

	envp = list_to_char(&p->env_list, NULL);
	p->internal_env = envp;
	if (p->ast && p->ast->argv && p->ast->argv[0]  && is_builtin(p->ast->argv))
		builtin(p->ast->argv, p);
	else
		execute(p->ast, envp);
	free_ast(p->ast);
	free_token_list(p->token);
	ft_free_str_arr(envp);
	p->ast = NULL;
	p->token = NULL;
	p->internal_env = NULL;
	return (0);
}

int main(int ac, char **av, char **envp)
{
	t_parsing	*p;
	int			res;

	(void)ac;
	(void)av;
	p = init(envp);
	if (!p)
		return (1);
	get_parsing_struct(&p);
	while (1)
	{
		setup_sig_interactive();
		res = ft_readline(p, "> ");
		if (res == 1)
			break ;
		else if (!res)
			process_command(p);
	}
	final_cleanup(p);
	return (0);
}
