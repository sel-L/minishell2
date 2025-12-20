/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 19:12:12 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/11 09:34:11 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/parsing.h"
#include "main_minishell.h"

/// @brief Find a specific node
/// @param to_find 
/// @param list 
/// @return Pointer to the node
t_env_list	*find_env_key(char *to_find, t_env_list **list)
{
	t_env_list	*temp;

	temp = *list;
	if (!to_find || !list)
		return (NULL);
	while (temp)
	{
		if (ft_strcmp(to_find, temp->front) == 0)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

/// @brief Delete a node from the env_list 
/// @param list 
/// @return updated env_list
t_env_list	**delete_node(t_env_list **list)
{
	t_env_list	*temp;

	if (!list || !*list)
		return (NULL);
	temp = *list;
	*list = temp->next;
	if (*list)
		(*list)->prev = NULL;
	free (temp->env_val);
	free (temp->front);
	free (temp);
	return (list);
}

/// @brief free entire env list
/// @param env_list 
void	free_env(t_env_list **env_list)
{
	t_env_list	*temp;

	if (!env_list)
		return ;
	while ((*env_list))
	{
		temp = (*env_list)->next;
		free((*env_list)->env_val);
		free((*env_list)->front);
		free(*env_list);
		*env_list = temp;
	}
}

/// @brief Change the value of a specific node
/// @param src 
/// @param list 
/// @return flag, 0 for success 1 for fail
int	change_value(char *src, t_env_list **list)
{
	t_env_list	*temp;
	int			len;
	char		*front;
	char		*ori;

	if (!src || !list || !*list)
		return (1);
	ori = src;
	len = 0;
	while (src[len] && src[len] != '=')
		len++;
	front = ft_substr(ori, 0, len);
	if (!front)
		return (1);
	temp = find_env_key(front, list);
	if (!temp)
		return (free(front), 1);
	free (temp->env_val);
	temp->env_val = ft_substr(ori, len + 1, ft_strlen(ori) - len - 1);
	if (!temp->env_val)
		return (free(front), 1);
	return (free(front), 0);
}

/// @brief Add node into env_list
/// @param node 
/// @param list 
/// @return flag, 0 for success 1 for fail
int	add_env_node(t_env_list *node, t_env_list **list)
{
	t_env_list	*curr;

	if (*list == NULL)
		return ((*list = node), 0);
	node->next = NULL;
	node->prev = NULL;
	curr = *list;
	while (curr->next)
		curr = curr->next;
	curr->next = node;
	node->prev = curr;
	return (0);
}
