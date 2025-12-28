/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:16:01 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/26 15:47:26 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

char	*get_expanded_value(t_parsing *p, char *str)
{
	t_env_list	*list;
	int			size;
	int			i;
	char		*res;
	char		*expanded;

	list = p->env_list;
	size = 0;
	if (*str == '"')
		str++;
	if (*str == '$')
		str++;
	while (str[size] != ' ')
		size++;
	res = ft_substr(str, 0, size);
	expanded = get_value(res, &list);
	free(res);
	return(expanded);
}

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
