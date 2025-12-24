/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 15:16:01 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/24 11:13:19 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

char	*get_expanded_value(t_parsing *p, char *str)
{
	t_env_list	*list;
	int			size;
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
	int	i;

	i = 0;
	while(str[i] && str[i] != '\'')
	{
		if (str[i] == '"')
			return ((*flag = !(*flag)), NULL);
		i++;
	}
	return (NULL);
}

char	*expansion(t_parsing *p, char *str)
{
	char	*res;
	char	*value;

	while (str)
	{
		if (*str == '\'')
			str += single_quoted(str);
		else if (*str == '"')
			value = double_quoted(p, str);
		
		res = ft_strjoin(res, *str);
	}
}