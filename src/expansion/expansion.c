/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:16:01 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/30 16:16:10 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

void	*expandable(char *str, int *flag)
{
	int		i;
	char	s_quote;

	i = 0;
	s_quote = (str[i] == '\'');
	while (str[i] == '\'')
		i++;
	while(str[i])
	{
		if (str[i] == '\'' && s_quote)
			s_quote = !s_quote;
		if (str[i] == '"' && !s_quote)
			return ((*flag = !(*flag)), NULL);
		i++;
	}
	return (NULL);
}

char	*quote_remover(char *str)
{
	char	*res;
	char	quote;
	int		i;
	
	i = 0;
	quote = '\0';
	res = ft_strdup("");
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '"') && !quote)
			quote = str[i];
		else if (str[i] == quote)
			quote = '\0';
		else
			res = ft_charjoin(res, str[i]);
		i++;
	}
	return (res);
}

char	*handle_dollar(char *str, int *i, t_parsing *p)
{
	char	*var_name;
	char	*var_value;
	char	*res;

	var_name = extract_expandable(&str[*i]);
	if (!ft_strcmp(var_name, "$"))
	{
		res = ft_strdup("$");
		*i += 1;
	}
	else
	{
		var_value = get_value(var_name + 1, &p->env_list);
		if (var_value)
			res = ft_strdup(var_value);
		else
			res = ft_strdup("");
		*i += ft_strlen(var_name);
	}
	free(var_name);
	return (res);
}

char	*expansion(char *str, t_parsing *p)
{
	char	*res;
	char	quote;
	int		i;

	res = ft_strdup("");
	i = 0;
	quote = '\0';
	while (str[i])
	{
		update_quote_state(str[i], &quote);
		if (str[i] == '$' && quote != '\'')
			res = ft_strjoin_then_free(res, handle_dollar(str, &i, p));
		else
		{
			res = ft_charjoin(res, str[i]);
			i++;
		}
	}
	return (res);
}

char	*expand_and_remove_quotes(char *str, t_parsing *p)
{
	char	*expanded;
	char	*quotes_proccessed;

	if (!str || !*str)
		return (ft_strdup(""));
	expanded = expansion(str, p);
	quotes_proccessed = quote_remover(expanded);
	free(str);
	free(expanded);
	return (quotes_proccessed);
}
