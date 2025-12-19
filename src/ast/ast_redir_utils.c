/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:03:48 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/19 16:01:16 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

int	append_args_after_redir(t_ast *ast, t_token **token)
{
	if (!ast || !token)
		return (0);
	while ((*token) && (*token)->type != PIPE)
	{
		if (is_redir((*token)->type))
		{
			if ((*token)->next)
				*token = (*token)->next->next;
			else
				*token = (*token)->next;
			continue ;
		}
		if ((*token) && (*token)->type == WORD)
		{
			ast->argv = ft_2d_append_back(ast->argv, (*token)->value);
			if (!ast->argv)
				return (0);
		}
		*token = (*token)->next;
	}
	return (1);
}

void	append_redir_back(t_redir *redir, t_redir **redir_list)
{
	t_redir	*temp;

	if (!redir || !redir_list)
		return ;
	if (!*redir_list)
	{
		*redir_list = redir;
		return ;
	}
	temp = *redir_list;
	while (temp->next)
		temp = temp->next;
	temp->next = redir;
}

t_redir	*create_redir_node(char *file_dest, t_token_type type)
{
	t_redir	*redir;

	if (!file_dest)
		return (NULL);
	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->file = ft_strdup(file_dest);
	if (!redir->file)
		return (free(redir), NULL);
	redir->type = type;
	redir->next = NULL;
	return (redir);
}

void	free_redir_list(t_redir *redir)
{
	t_redir	*temp;

	while (redir)
	{
		temp = redir->next;
		free(redir->file);
		free(redir);
		redir = temp;
	}
}
