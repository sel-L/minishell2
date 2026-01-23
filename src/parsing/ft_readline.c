/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:26:28 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/20 22:28:22 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include "main_minishell.h"

int	parse(char *str, t_parsing *parse)
{
	if (!str)
		return (1);
	parse->token = tokenizer(str);
	if (validator(parse->token) != 0)
		return (free_token_list(parse->token), 1);
	parse->ast = ast(&parse->token);
	process_ast_expansion(parse->ast, parse);
	return (0);
}

static int	is_blank(char *s)
{
	int	i;

	i = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	return (s[i] == '\0');
}

int	ft_readline(t_parsing *p, char *prompt)
{
	char		*str;
	static int	line_count;

	str = readline(prompt);
	if (g_signal == SIGINT)
	{
		g_signal = 0;
		if (str)
			free(str);
		rl_on_new_line();
		rl_redisplay();
		return (2);
	}
	if (!str)
		return (1);
	if (*str == '\0' || is_blank(str))
		return (free(str), 2);
	add_history(str);
	// if (ft_strcmp(str, "exit") == 0)
	// 	return (free(str), 1);
	line_count++;
	p->line_count = line_count;
	if (parse(str, p) == 1)
		return (free(str), rl_clear_history(), 2);
	free(str);
	return (0);
}
