/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:07:46 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/14 15:30:06 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

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
		return ;
	temp = *token_list;
	while(temp)
		temp = temp->next;
	if (token->next == NULL)
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
	t_token	*head;
	t_token	*temp;

	if (!list || !*list)
		return (free(token), NULL);
	head = *list;
	temp = create_token(token, type);
	if (!temp)
		(free(token), NULL);
	append_token_to_list(list, temp);
	return (head);
}
