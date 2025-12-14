/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:25:55 by joloo             #+#    #+#             */
/*   Updated: 2025/12/11 18:08:58 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while(temp->next)
	{
		if (ft_strcmp("?", temp->front) == 0)
			temp = temp->next;
		printf("declare -x ");
		printf("%s", temp->front);
		printf("=\"");
		printf("%s\"\n", temp->env_val);
		temp = temp->next;
	}
	free_env(&head);
}

void	export(t_env_list **env)
{
	char		**env_list;
	char		**sorted;

	if (!env || !*env)
		return (perror("env error"));
	env_list = list_to_char(env, NULL);
	if (!env_list)
		return (free_env(env) ,perror("export: env_list error"));
	sorted = sort_env(env_list);
	print_sorted_env(sorted);
	ft_free_str_arr(sorted);
}
