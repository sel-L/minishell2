/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 18:09:45 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/27 23:06:12 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

void	expand_ast_redir(t_ast *node, t_parsing *p);
void	expand_ast_argv(t_ast *node, t_parsing *p);

int	has_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

void	rebuild_argv(char **old, char **new, t_parsing *p)
{
	int		i;
	int		j;
	char	*expanded;

	i = 0;
	j = 0;
	while (old[i])
	{
		expanded = expand_and_remove_quotes(old[i], p);
		if (expanded[0] != '\0' || has_quotes(old[i]))
			new[j++] = expanded;
		else
			free(expanded);
		free(old[i]);
		i++;
	}
	new[j] = NULL;
}

void	process_ast_expansion(t_ast *node, t_parsing *p)
{
	if (!node)
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
	char	**new_argv;
	int		count;

	if (!node->argv)
		return ;
	count = 0;
	while (node->argv[count])
		count++;
	new_argv = malloc(sizeof(char *) * (count + 1));
	if (!new_argv)
		return ;
	rebuild_argv(node->argv, new_argv, p);
	free(node->argv);
	node->argv = new_argv;
}
