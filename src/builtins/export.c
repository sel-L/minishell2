/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:22:29 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/18 11:52:50 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
// #include "parsing.h"
#include "main_minishell.h"

char	**sort_env(char	**env)
{
	int			i;
	int			j;
	const int	size = ft_strarr_len(env);
	char		*temp;

	i = 0;
	while(i < size)
	{
		j = i + 1;
		while(j < size)
		{
			if (ft_strcmp(env[i], env[j]) > 0)
			{
				temp = env[i];
				env[i] = env[j];
				env[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (env);
}

void	print_sorted_env(char **sorted_env)
{
	t_env_list	*temp;
	t_env_list	*head;

	temp = env_to_list(sorted_env);
	head = temp;
	while(temp)
	{
		if (ft_strcmp("?", temp->front) == 0)
			temp = temp->next;
		printf("declare -x %s=\"%s\"\n", temp->front, temp->env_val);
		temp = temp->next;
	}
	free_env(&head);
}

void	*export_without_arg(t_env_list **env)
{
	char		**env_list;
	char		**sorted;

	if (!env || !*env)
		return (ft_putendl_fd("Export: Invalid env", 2), NULL);
	env_list = list_to_char(env, NULL);
	if (!env_list)
		return (free_env(env) ,ft_putendl_fd("Export: env_list error", 2), NULL);
	sorted = sort_env(env_list);
	print_sorted_env(sorted);
	ft_free_str_arr(sorted);
	return (NULL);
}

t_env_list	**export_with_arg(t_env_list **env , char *arg)
{
	char	*front;
	char	*value;
	char	*pos;

	if (!env || !*env)
		return (ft_putendl_fd("Export: Invalid env", 2), NULL);
	pos = ft_strchr(arg, '=');
	if (!pos)
	{
		if (find_env_key(arg, env) == NULL)
			add_env(arg, env);
		return (env);
	}
	front = ft_substr(arg, 0, (pos - arg));
	value = ft_strdup(pos + 1);
	if (find_env_key(front, env) != NULL)
		change_key_value(front, value, env);
	else
		add_env(arg, env);
	return (free(front), free(value), env);
}

void	*ft_export(t_env_list **env, char **arg)
{
	int	i;

	i = 1;
	if (!env || !*env || !arg || !*arg)
		return (ft_putendl_fd("Export: Invalid arguments", 2), NULL);
	if (arg[1])
	{
		while (arg[i])
		{
			export_with_arg(env, arg[i]);
			i++;
		}
	}
	else
		export_without_arg(env);
	return (NULL);
}
