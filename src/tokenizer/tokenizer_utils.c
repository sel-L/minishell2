/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:07:46 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/15 17:19:21 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "tokenizer.h"
#include "main_minishell.h"

void	free_single_token(t_token *token)
{
	if (!token)
		return ;
	if (token->value)
		free(token->value);
	free(token);
}

void	append_token_to_list(t_token **token_list, t_token *token)
{
	t_token	*temp;

	if (!token_list || !*token_list)
	{
		*token_list = token;
		return ;
	}
	temp = *token_list;
	while (temp->next)
		temp = temp->next;
	temp->next = token;
	return ;
}

t_token	*create_token(char *value, t_token_type type)
{
	t_token	*token;

	if (!value)
		return (NULL);
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->value = ft_strdup(value);
	if (!token->value)
		return (free_single_token(token), NULL);
	token->type = type;
	token->next = NULL;
	return (token);
}

t_token	*add_and_append_token(t_token **list, t_token_type type, char *token)
{
	t_token	*temp;

	temp = create_token(token, type);
	if (!temp)
		return (NULL);
	append_token_to_list(list, temp);
	return (*list);
}

int	is_op(char c)
{
	return (c == '<' || c == '>' || c == '|');
}
