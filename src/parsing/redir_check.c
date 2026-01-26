/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 16:17:14 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/27 01:08:58 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/parsing.h"
#include "main_minishell.h"

int	redir_val(t_token *token);
int	pipe_val(t_token *token);

/// @brief loop through all token. check for pipe and redirections
/// @param token 
/// @return 0 for success, 1 for fail
int	validator(t_token *token)
{
	t_token	*temp;

	if (!token || token->type == PIPE)
		return (ft_putendl_fd("syntax error near unexpected token", 2), 2);
	temp = token;
	while (temp)
	{
		if (redir_val(temp) == 1)
			return (2);
		if (pipe_val(temp) == 1)
			return (2);
		temp = temp->next;
	}
	if (!token->next && token->type == PIPE)
		return (1);
	return (0);
}

/// @brief Return true if type is redir
/// @param type
/// @return true if is redir and false if is not
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
		if (!token->next || (token->next->type != WORD && !is_redir(token->next->type)))
		{
			if (!token->next)
				ft_putendl_fd("syntax error near unexpected token `newline'", 2);
			else
			{
				ft_putstr_fd("syntax error near unexpected token `", 2);
				ft_putstr_fd(token->next->value, 2);
				ft_putendl_fd("'", 2);
			}
			return (1);
		}
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
		{
			if (!token->next)
				ft_putendl_fd("syntax error near unexpected token `newline'", 2);
			else
			{
				ft_putstr_fd("syntax error near unexpected token `", 2);
				ft_putstr_fd(token->next->value, 2);
				ft_putendl_fd("'", 2);
			}
			return (1);
		}
	}
	return (0);
}
