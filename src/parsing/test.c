/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:38:53 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/30 16:00:27 by wshou-xi         ###   ########.fr       */
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

t_parsing	*init_half(char **envp)
{
	t_parsing	*p;

	p = malloc(sizeof(t_parsing));
	*p = (t_parsing){0};
	*p = (t_parsing){.env_list = env_to_list(envp)};
	return (p);
}

int	parsing(char *str, t_parsing *parse)
{
	t_token	*head;

	if (!str)
		return (1);
	parse->token = tokenizer(str);
	head = parse->token;
	if (validator(parse->token) != 0)
		return (free_token_list(parse->token), 1);
	parse->ast = build_ast(&parse->token);
	parse->token = head;
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_parsing	*p;
	char		*str;
	char		*expanded;
	char		*proccessed;

	p = init_half(envp);
	(void)ac;
	(void)av;
	while (1)
	{
		str = readline("> ");
		add_history(str);
		expanded = expansion(str, p);
		printf("Expanded : %s\n", expanded);
		proccessed = quote_remover(expanded);
		printf("Quote removed: %s\n", proccessed);
		free_token_list(p->token);
		free(str);
		free(expanded);
		free(proccessed);
	}
	free_env(&p->env_list);
	free(p);
	return (0);
}