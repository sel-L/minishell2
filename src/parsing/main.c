/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:21 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/17 17:21:54 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

t_parsing	*init(char **envp);

int	parsing(char *str, t_parsing *parse)
{
	if (!str)
		return (1);
	parse->token = tokenizer(str);
	if (validator(parse->token) != 0)
		return (free_token_list(parse->token), 1);
	print_token_list(&parse->token);
	return (0);
}

t_parsing	*init(char **envp)
{
	t_parsing	*parse;

	if (!envp)
		return (ft_putendl_fd("init: no env\n", 2), NULL);
	parse = malloc(sizeof(t_parsing));
	if (!parse)
		return (ft_putendl_fd("init: malloc failed\n", 2), NULL);
	parse->env_list = env_to_list(envp);
	if (!parse->env_list)
		return (free(parse), ft_putendl_fd("init: env error\n", w), NULL);
	parse->internal_env = malloc(sizeof(char *));
	if (!parse->internal_env)
		return (free);
	ft_bzero(parse->internal_env, sizeof(char *));
	return (parse);
}

void	garbage_collector(t_parsing	*p, char **argv, char *str)
{
	if (argv || *argv)
		free_argv(argv);
	if ((*p).token)
		free_token_list(p->token);
	if (str)
		free(str);
}

int main(int ac, char **av, char **envp)
{
	t_parsing	*p;
	int			res;
	char		**argv;

	(void)ac;
	(void)av;
	if((p = init(envp)) == NULL)
		return (1);
	while (1)
	{
		res = ft_readline(p, "> ");
		if (res == 1)
			break ;
		else if (res == 2)
			continue ;
		argv = tok_to_argv(p->token);
		if (is_builtin(argv) == 1)
			builtin(argv, p);
		garbage_collector(p ,argv, NULL);
	}
	rl_clear_history();
	free_env(&p->env_list);
	free(p);
	return (0);
}
