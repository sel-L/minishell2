/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:09:45 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/26 22:07:29 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

void	expand_ast_redir(t_ast *node, t_parsing *p);
void	expand_ast_argv(t_ast *node, t_parsing *p);

void	process_ast_expansion(t_ast *node, t_parsing *p)
{
	if(!node)
		return ;
	if (node->type == CMD)
	{
		expand_ast_argv(node, p);
		expand_ast_redir(node, p);
	}
	process_ast_expansion(node->left, p);
	process_ast_expansion(node->right, p);
}

void	expand_ast_redir(t_ast *node, t_parsing *p)
{
	t_redir	*temp_redir;
	char	*temp;

	temp_redir = node->redir;
	while (temp_redir)
	{
		temp = expand_and_remove_quotes(temp_redir->file, p);
		free(temp_redir->file);
		temp_redir->file = ft_strdup(temp);
		free(temp);
		temp_redir = temp_redir->next;
	}
}

void	expand_ast_argv(t_ast *node, t_parsing *p)
{
	char	**node_argv;
	char	*temp_expand;
	int		i;

	if (!node->argv)
		return ;
	node_argv = node->argv;
	i = 0;
	while (node_argv[i])
	{
		temp_expand = expand_and_remove_quotes(node_argv[i], p);
		free(node_argv[i]);
		node_argv[i] = ft_strdup(temp_expand);
		free(temp_expand);
		i++;
	}
}
