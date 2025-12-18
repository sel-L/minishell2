/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:03:48 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/18 19:08:16 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

void	append_redir_back(t_redir *redir, t_redir **redir_list)
{
	t_redir	*temp;

	if (!redir_list)
		*redir_list = redir;
	temp = redir;
	while(temp)
		temp = temp->next;
	temp->next = redir;
	return ;
}

t_redir	*create_redir_node(char *file_dest, t_node_type type)
{
	t_redir	*redir;

	if (!file_dest)
		return (NULL);
	redir = malloc(sizeof(t_redir));
	if (!redir)
		return (NULL);
	redir->file = ft_strdup(file_dest);
	redir->type = type;
	redir->next = NULL;
	return (redir);
}
