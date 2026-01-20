/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:21 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/20 01:09:24 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/parsing.h"
#include "main_minishell.h"
int	g_signal;

static void cleanup_on_exit(int status, void *arg)
{
	(void)status;
	final_cleanup((t_parsing *)arg);
}

t_parsing	*init(char **envp)
{
	t_parsing	*parse;

	//Initialize parsing struct with envp
	if (!envp)
		return (ft_putendl_fd("init: no env\n", 2), NULL);
	parse = malloc(sizeof(t_parsing));
	if (!parse)
		return (ft_putendl_fd("init: malloc failed\n", 2), NULL);
	ft_bzero(parse, sizeof(t_parsing));
	parse->env_list = env_to_list(envp);
	if (!parse->env_list)
		return (free(parse), ft_putendl_fd("init: env error\n", 2), NULL);
	parse->internal_env = NULL;
	return (parse);
}

int	process_command(t_parsing *p)
{
	char	**envp;

	envp = list_to_char(&p->env_list, NULL);
	p->internal_env = envp;
	if (p->ast && p->ast->argv && is_builtin(p->ast->argv) == 1)
		builtin(p->ast->argv, p);
	else
		execute(p->ast, envp);
	garbage_collector(p ,NULL, NULL);
	ft_free_str_arr(envp);
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
	on_exit(cleanup_on_exit, p);
	while (1)
	{
		setup_sig_interactive();
		res = ft_readline(p, "> ");
		if (res == 1)
			break ;
		else if (!res)
			process_command(p);
	}
	return (0);
}
