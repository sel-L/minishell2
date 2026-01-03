/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:34:04 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/01 16:39:44 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <parsing.h>
#include "main_minishell.h"

void	garbage_collector(t_parsing	*p, char **argv, char *str)
{
	if (argv)
		free_argv(argv);
	if (p->token)
	{
		free_token_list(p->token);
		p->token = NULL;
	}
	if (str)
		free(str);
	free_ast(p->ast);
}

void	final_cleanup(t_parsing *p)
{
	free_env(&p->env_list);
	ft_free_str_arr(p->internal_env);
	free(p);
}
