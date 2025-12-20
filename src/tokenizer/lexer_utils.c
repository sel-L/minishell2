/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:58:21 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/15 23:52:55 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "tokenizer.h"
#include "main_minishell.h"

t_lexer	*init_lex(char *input)
{
	t_lexer	*lex;

	lex = malloc(sizeof(t_lexer));
	if (!lex)
		return (NULL);
	ft_bzero(lex, sizeof(t_lexer));
	lex->lex_start = input;
	lex->lex_end = input;
	return (lex);
}

void	reset_pos(t_lexer *lex)
{
	if (!lex)
		return ;
	lex->lex_start = lex->lex_end;
}

void	print_token_list(t_token **token)
{
	t_token	*temp;

	temp = *token;
	while (temp)
	{
		printf("token:\t\t%s\n", temp->value);
		printf("token type: %d\n", temp->type);
		temp = temp->next;
	}
}

int	ft_strarr_len(char **str)
{
	int	size;

	if (!str)
		return (0);
	size = 0;
	while(str[size])
		size++;
	return (size);
}

void	ft_free_str_arr(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}
