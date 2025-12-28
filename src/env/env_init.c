/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:35:28 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/11 08:56:50 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/parsing.h"
#include "main_minishell.h"

/// @brief loop through the envp from main and call add_env_list
/// @param env 
/// @return env linked list
t_env_list	*env_to_list(char **env)
{
	t_env_list	*env_list;
	int			i;

	env_list = NULL;
	if (!env || !*env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (add_env(env[i], &env_list) == 1)
			return (free_env(&env_list), NULL);
		i++;
	}
	return (env_list);
}

/// @brief Convert env_list to char ** for execve
/// @param list
/// @return 2d array, envp
char	**list_to_char(t_env_list **list, char **res)
{
	t_env_list	*temp;
	char		*temp_s;
	char		*front;
	int			size;
	int			i;

	if (!list || !*list)
		return (NULL);
	temp = *list;
	size = env_size(list);
	res = malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		front = ft_strjoin(temp->front, "=");
		temp_s = ft_strjoin(front, temp->env_val);
		free(front);
		res[i] = ft_strdup(temp_s);
		free(temp_s);
		temp = temp->next;
		i++;
	}
	res[i] = NULL;
	return (res);
}
