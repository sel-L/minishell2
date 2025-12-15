/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:25:31 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/15 17:19:14 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	ft_isspace(char c)
{
	return (c == 32 || c == '\t');
}

int	identify_op(char *op)
{
	char	*temp_next;

	temp_next = op;
	temp_next++;
	if (*op == '>' && *temp_next == '>')
		return (APPEND);
	else if (*op == '<' && *temp_next == '<')
		return (HEREDOC);
	else if (*op == '>')
		return (R_OUT);
	else if (*op == '<')
		return (R_IN);
	else if (*op == '|')
		return (PIPE);
	return (-1);
}

void	*create_word_token(t_lexer *lex, t_token **list)
{
	char	*temp;

	if (lex->lex_start >= lex->lex_end)
		return (list);
	temp = ft_substr(lex->lex_start, 0,
			lex->lex_end - lex->lex_start);
	if (!temp)
		return (NULL);
	if (!add_and_append_token(list, WORD, temp))
		return (free(temp), NULL);
	return (free(temp), list);
}

void	*create_op_token(t_lexer *lex, t_token **list)
{
	char	op[3];
	int		len;
	int		type;

	op[0] = *lex->lex_end;
	len = 1;
	if (lex->lex_end[1] == *lex->lex_end
		&& (*lex->lex_end == '<' || *lex->lex_end == '>'))
	{
		op[1] = *lex->lex_end;
		len = 2;
	}
	op[len] = '\0';
	type = identify_op(op);
	if (type == -1)
		return (NULL);
	if (!add_and_append_token(list, type, op))
		return (NULL);
	lex->lex_end += len;
	return (list);
}

void	skip_whitespace(t_lexer *lex)
{
	while (ft_isspace(*lex->lex_end))
		lex->lex_end++;
}
