/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:40:49 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/18 14:10:38 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include <string.h>
#include <uchar.h>

/// @brief env_list size
/// @param list 
/// @return Size of env
int	env_size(t_env_list **list)
{
	t_env_list	*temp;
	int			i;

	if (!list || !*list)
		return (0);
	i = 0;
	temp = *list;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

/// @brief print env
/// @param env 
/// @param flag 
void	print_env(t_env_list *env)
{
	int		i;

	i = 0;
	if (!env)
		return ;
	while (env)
	{
		if (env->front[0] == '?')
			env = env->next;
		printf("%s=%s\n", env->front, env->env_val);
		env = env->next;
		i++;
	}
	return ;
}

/// @brief Get value from a key
/// @param key 
/// @param list 
/// @return value of the specific key
char	*get_value(char *key, t_env_list **list)
{
	t_env_list	*temp;
	char		*res;


	if (!key || !list || !*list)
		return (NULL);
	temp = find_env_key(key, list);
	if (temp == NULL)
		return (ft_calloc(1, sizeof(char)));
	res = ft_strdup(temp->env_val);
	return (res);
}

int	key_value_len(char *key, t_env_list **list)
{
	char	*temp;
	int		res;

	temp = get_value(key, list);
	res = ft_strlen(temp);
	return (free(temp), res);
}

char	**ft_strarrdup(char **str)
{
	char	**temp;
	int		size;
	int		i;

	if (!str)
		return (NULL);
	size = ft_strarr_len(str);
	i = 0;
	temp = malloc(sizeof(char *) * (size + 1));
	if (!temp)
		return (NULL);
	while(i < size)
	{
		temp[i] = ft_strdup(str[i]);
		if (!temp[i])
			return (ft_free_str_arr(temp), NULL);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}
