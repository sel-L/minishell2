/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:21:53 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/21 19:45:52 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "tokenizer.h"
#include "main_minishell.h"

void	free_token_list(t_token *list)
{
	t_token	*temp;

	if (!list)
		return ;
	while (list)
	{
		temp = list;
		list = list->next;
		free_single_token(temp);
	}
}

int	scan_word(t_lexer *lex)
{
	char	q;

	while (*lex->lex_end && !ft_isspace(*lex->lex_end)
		&& !is_op(*lex->lex_end))
	{
		if (*lex->lex_end == '\'' || *lex->lex_end == '"')
		{
			q = *lex->lex_end++;
			while (*lex->lex_end && *lex->lex_end != q)
				lex->lex_end++;
			if (*lex->lex_end != q)
				return (0);
			lex->lex_end++;
		}
		else
			lex->lex_end++;
	}
	return (1);
}

int	process_token(t_lexer *lex, t_token **list)
{
	if (is_op(*lex->lex_end))
	{
		if (!create_op_token(lex, list))
			return (0);
		return (1);
	}
	if (!scan_word(lex))
		return (0);
	if (!create_word_token(lex, list))
		return (0);
	return (1);
}

t_token	*tokenizer(char *input)
{
	t_lexer	*lex;
	t_token	*list;

	list = NULL;
	lex = init_lex(input);
	if (!lex)
		return (NULL);
	while (*lex->lex_end)
	{
		skip_whitespace(lex);
		if (!*lex->lex_end)
			break ;
		lex->lex_start = lex->lex_end;
		if (process_token(lex, &list) == 0)
			return (free(lex), free_token_list(list),
				ft_putendl_fd("Tokenizer: invalid token.", 2), NULL);
	}
	return (free(lex), list);
}
