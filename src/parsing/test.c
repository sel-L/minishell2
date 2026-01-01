/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:38:53 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/01 15:27:52 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

// void	*init_everything(char *str, char **envp)
// {
// 	t_parsing	*p;
// 	t_token		*head;

// 	p->token = tokenizer(str);
// 	head = p->token;
// 	*p = (t_parsing){.ast = build_ast(&p->token)};
// 	if (validator(p->token) != 0)
// 		return (free_token_list(p->token), NULL);
// 	p->token = head;
// }

// t_parsing	*init_half(char **envp)
// {
// 	t_parsing	*p;

// 	p = malloc(sizeof(t_parsing));
// 	*p = (t_parsing){0};
// 	*p = (t_parsing){.env_list = env_to_list(envp)};
// 	return (p);
// }

// int	parsing(char *str, t_parsing *parse)
// {
// 	t_token	*head;

// 	if (!str)
// 		return (1);
// 	parse->token = tokenizer(str);
// 	head = parse->token;
// 	if (validator(parse->token) != 0)
// 		return (free_token_list(parse->token), 1);
// 	parse->ast = build_ast(&parse->token);
// 	parse->token = head;
// 	return (0);
// }

// int	main(int ac, char **av, char **envp)
// {
// 	t_parsing	*p;
// 	char		*str;
// 	char		*res;

// 	p = init_half(envp);
// 	(void)ac;
// 	(void)av;
// 	while (1)
// 	{
// 		str = readline("> ");
// 		add_history(str);
// 		res = expand_and_remove_quotes(str, p);
// 		printf("Res is: %s\n", res);
// 		free_token_list(p->token);
// 		free(res);
// 		free(str);
// 	}
// 	free_env(&p->env_list);
// 	free(p);
// 	return (0);
// }