/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:21:53 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/14 16:53:22 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

int	is_op(char c)
{
	return (c == '<' || c == '>' || c == '|' || c == 32);
}

t_token	*tokenizer(t_token *list, char *input)
{
	if (!input || !input[0])
		return (NULL);
}

int	quote_size(char *str, int i)
{
	int	s_quote;
	int	d_quote;

	if (!str)
		return (-1);
	s_quote = 0;
	d_quote = 0;
	if (str[i] == '\'')
		s_quote = 1;
	if (str[i] == '"')
		d_quote = 1;
	i++;
	while(str[i])
	{
		if (str[i] == '"' && d_quote)
			break ;
		if (str[i] == '\'' && s_quote)
			break ;
		i++;
	}
	return (i - 1);
}

char	*find_token(char *input)
{
	static int		i;
	char			*temp;

	if (!input || !input[0])
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (is_op(input[i]))
			return (temp);
		if (input[i] == '\'' || input[i] == '"')
		{
			temp = ft_substr(input, i, quote_size(input, i));
			i += quote_size(input, i);
			return (temp);
		}
	}
}
