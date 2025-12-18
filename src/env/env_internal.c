/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_internal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:28:55 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/18 10:25:37 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "m_env.h"

char	*get_int_env(char *target, char **list)
{
	int	i;
	int	len;

	if (!list || !target)
		return (NULL);
	len = ft_strlen(target);
	i = 0;
	while(list[i])
	{
		if (ft_strncmp(list[i], target, len) == 0 && list[i][len] == '=')
			return (ft_strdup(list[i] + len + 1));
		i++;
	}
	return (NULL);
}

char	*find_int_env(char *target, char **list)
{
	char	**temp;
	char	*value;

	temp = list;
	while (temp)
	{
		if (ft_strncmp(target, *temp, ft_strlen(target)) == 0)
			break ;
		temp++;
	}
	if (!temp)
		return (NULL);
	while (*value != '=')
		value++;
	return (ft_substr(value, 1, ft_strlen(value)));
}

char	**add_int_env(char *target, char *value, char **list)
{
	char	*half_value;
	char	*res;

	if (!target || !value)
		return (NULL);
	if ((find_int_env(target, list) != NULL) && list)
		return (NULL);
	else
	{
		half_value = ft_strjoin(target, "=");
		if (!half_value)
			return (NULL);
		res = ft_strjoin(half_value, value);
		if (!value)
			return (free(half_value), NULL);
		list = ft_2d_append_back(list, res);
		return (free(half_value), free(res), list);
	}
}

void	*print_int_env(char **int_env)
{
	int	i;

	if (!int_env || !*int_env)
		return (NULL);
	i = 0;
	while(int_env[i])
	{
		printf("declare -x %s\n", int_env[i]);
		i++;
	}
	return (NULL);
}
