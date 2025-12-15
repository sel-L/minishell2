/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:17:14 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/02 13:43:55 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

int	redir_val(t_token *token);
int	pipe_val(t_token *token);

/// @brief loop through all token. check for pipe and redirections
/// @param token 
/// @return 0 for success, 1 for fail
int	validator(t_token *token)
{
	t_token	*temp;

	if (!token || token->type == PIPE)
		return (perror("syntax error near unexpected token"), 2);
	temp = token;
	while (temp)
	{
		printf("token type is: %d\n", token->type);
		if (redir_val(temp) == 1)
			return (perror("syntax error near unexpected token"), 2);
		if (pipe_val(temp) == 1)
			return (perror("syntax error near unexpected token"), 2);
		temp = temp->next;
	}
	if (!token->next && token->type == PIPE)
		return (1);
	return (0);
}

int	is_redir(t_token_type t)
{
	return (t == REDIR_IN || t == REDIR_OUT || t == APPEND || t == HERE_DOC);
}

/// @brief pipe validation
/// @param token 
/// @return 0 for success 1 for fail
int	pipe_val(t_token *token)
{
	if (!token)
		return (0);
	if (token->type == PIPE)
	{
		if (!token->next || token->next->type != WORD)
			return (1);
	}
	return (0);
}

/// @brief redirection check
/// @param token 
/// @return 0 for success, 1 for error
int	redir_val(t_token *token)
{
	if (!token)
		return (0);
	if (is_redir(token->type))
	{
		if (!token->next || token->next->type != WORD)
			return (1);
	}
	return (0);
}
