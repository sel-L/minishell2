/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:22:29 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/02/03 14:27:23 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
// #include "parsing.h"
#include "main_minishell.h"

void	print_sorted_env(char **sorted_env)
{
	t_env_list	*temp;
	t_env_list	*head;

	temp = env_to_list(sorted_env);
	head = temp;
	while (temp)
	{
		if (ft_strcmp("?", temp->front) == 0)
			temp = temp->next;
		if (ft_strlen(temp->env_val) >= 1)
			printf("declare -x %s=\"%s\"\n", temp->front, temp->env_val);
		else
			printf("declare -X %s=\"\"\n", temp->front);
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
		return (free_env(env),
			ft_putendl_fd("Export: env_list error", 2), NULL);
	sorted = sort_env(env_list);
	print_sorted_env(sorted);
	ft_free_str_arr(sorted);
	return (NULL);
}

t_env_list	**export_with_arg(t_env_list **env, char *arg)
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
			add_env_node(empty_node(arg), env);
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

int	ft_export(t_env_list **env, char **arg)
{
	int	i;

	i = 1;
	if (!env || !*env || !arg || !*arg)
		return (ft_putendl_fd("Export: Invalid arguments", 2), 1);
	if (arg[1])
	{
		while (arg[i])
		{
			if (!is_valid_identifier(arg[i]))
			{
				ft_putstr_fd("minishell: export `", 2);
				ft_putstr_fd(arg[i], 2);
				ft_putendl_fd("': not a valid identifier", 2);
				return (1);
			}
			else
				export_with_arg(env, arg[i]);
			i++;
		}
	}
	else
		export_without_arg(env);
	return (0);
}
