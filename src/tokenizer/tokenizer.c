/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:21:53 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/20 22:27:44 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "tokenizer.h"
#include "main_minishell.h"

void	free_token_list(t_token *list)
{
	t_token	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		free_single_token(temp);
	}
}

void	*quoted(t_lexer *lex, t_token **list)
{
	char	quoted_c;

	while (*lex->lex_end)
	{
		if (*lex->lex_end == '\'' || *lex->lex_end == '"')
		{
			quoted_c = *lex->lex_end;
			lex->lex_end++;
			while (*lex->lex_end && *lex->lex_end != quoted_c)
				lex->lex_end++;
			if (*lex->lex_end == quoted_c)
				lex->lex_end++;
			else
				return (NULL);
		}
		else
			break ;
	}
	return (create_word_token(lex, list));
}

void	process_unquoted_word(t_lexer *lex)
{
	while (*lex->lex_end
		&& (!ft_isspace(*lex->lex_end))
		&& (!is_op(*lex->lex_end))
		&& *lex->lex_end != '\''
		&& *lex->lex_end != '"')
		lex->lex_end++;
}

int	process_token(t_lexer *lex, t_token **list)
{
	if (*lex->lex_end == '"' || *lex->lex_end == '\'')
	{
		if (quoted(lex, list) == NULL)
			return (0);
	}
	else if (is_op(*lex->lex_end))
	{
		if (!create_op_token(lex, list))
			return (0);
	}
	else
	{
		process_unquoted_word(lex);
		if (!create_word_token(lex, list))
			return (0);
	}
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
			return (free(lex),
				ft_putendl_fd("Tokenizer: invalid token.", 2), NULL);
	}
	return (free(lex), list);
}
