/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:11:02 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/30 15:44:30 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

void	update_quote_state(char c, char *quote)
{
	if ((c == '\'' || c == '"') && *quote == '\0')
		*quote = c;
	else
		*quote = '\0';
}

char	*ft_charjoin(char *str, char chr)
{
	char	temp[2];
	char	*res;

	if (!str)
		str = ft_strdup("");
	temp[0] = chr;
	temp[1] = '\0';
	res = ft_strjoin_then_free(str, temp);
	free(str);
	return (res);
}

char	*get_expanded_value(t_parsing *p, char *str)
{
	t_env_list	*list;
	int			size;
	char		*res;
	char		*expanded;

	list = p->env_list;
	size = 0;
	while (*str == '"')
		str++;
	if (*str == '$')
		str++;
	while (str[size] != ' ' && str[size] != '"')
		size++;
	res = ft_substr(str, 0, size);
	expanded = get_value(res, &list);
	free(res);
	if (!expanded)
		return (NULL);
	return(expanded);
}

char	*ft_strjoin_then_free(char *s1, char *s2)
{
	char	*res;

	if (!s1)
		return (ft_strdup(""));
	if (!s2)
		return (s1);
	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

/// @brief Extract str such as $HOME
/// @param str 
/// @return Eg. $HOME
char	*extract_expandable(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (str[i] == '$')
		i++;
	if (str[i] == '?')
		return (ft_strdup("$?"));
	if (!ft_isalpha(str[i]) && str[i] != '_')
		return (ft_strdup("$"));
	while(str[i] && (ft_isalpha(str[i]) || str[i] == '_'))
		i++;
	res = ft_substr(str, 0, i);
	return (res);
}
