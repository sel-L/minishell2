/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:49:21 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/17 09:38:17 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/parsing.h"
// #include "main_minishell.h"

// t_parsing	*init(char **envp);

// int	parsing(char *str, t_parsing *parse)
// {
// 	if (!str)
// 		return (1);
// 	parse->token = tokenizer(str);
// 	if (validator(parse->token) != 0)
// 		return (free_token_list(parse->token), 1);
// 	parse->ast = ast(&parse->token);
// 	process_ast_expansion(parse->ast, parse);
// 	return (0);
// }

// t_parsing	*init(char **envp)
// {
// 	t_parsing	*parse;

// 	//Initialize parsing struct with envp
// 	if (!envp)
// 		return (ft_putendl_fd("init: no env\n", 2), NULL);
// 	parse = malloc(sizeof(t_parsing));
// 	if (!parse)
// 		return (ft_putendl_fd("init: malloc failed\n", 2), NULL);
// 	parse->env_list = env_to_list(envp);
// 	if (!parse->env_list)
// 		return (free(parse), ft_putendl_fd("init: env error\n", 2), NULL);
// 	parse->internal_env = malloc(sizeof(char *));
// 	if (!parse->internal_env)
// 		return (ft_free_str_arr(parse->internal_env), free(parse), NULL);
// 	ft_bzero(parse->internal_env, sizeof(char *));
// 	return (parse);
// }

// int main(int ac, char **av, char **envp)
// {
// 	t_parsing	*p;
// 	int			res;
// 	char		**argv;

// 	(void)ac;
// 	(void)av;
// 	if((p = init(envp)) == NULL) // not norm free
// 		return (1);
// 	while (1)
// 	{
// 		res = ft_readline(p, "> ");
// 		if (res == 1)
// 			break ;
// 		if (res == 2)
// 			continue ;
// 		argv = tok_to_argv(p->token);
// 		if (is_builtin(argv) == 1)
// 			builtin(argv, p);
// 		print_ast(p->ast, 0);
// 		garbage_collector(p ,argv, NULL);
// 	}
// 	rl_clear_history();
// 	final_cleanup(p);
// 	return (0);
// }
