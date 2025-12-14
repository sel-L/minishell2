/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 23:48:14 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/05 17:51:36 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

static char	**new_2d(char *content)
{
	char	**temp;

	temp = malloc(sizeof(char *) * 2);
	if (!temp)
		return (NULL);
	temp[0] = ft_strdup(content);
	if (!temp[0])
		return (NULL);
	temp[1] = NULL;
	return (temp);
}

char	**ft_2d_append_back(char **ori, char *content)
{
	int		td_size;
	int		i;
	char	**temp;

	td_size = 0;
	i = 0;
	if (!ori)
		return (new_2d(content));
	while(ori[td_size])
		td_size++;
	temp = malloc(sizeof(char *) * (td_size + 2));
	if (!temp)
		return (ft_free_str_arr(ori), NULL);
	while(i < td_size)
	{
		temp[i] = ft_strdup(ori[i]);
		i++;
	}
	temp[i] = ft_strdup(content);
	temp[i + 1] = NULL;
	return ((ft_free_str_arr(ori)), temp);
}

void	free_node_list(t_node *node)
{
	t_node	*temp;

	while(node)
	{
		temp = node->next;
		free_node(node);
		node = temp;
	}
}

void	free_node(t_node *node)
{
	int	i;

	if (!node)
		return ;
	i = 0;
	while (node->argv && node->argv[i])
	{
		free(node->argv[i]);
		i++;
	}
	free(node->argv);
	free(node->cmd);
	free(node);
}

t_node	*create_node(char **argv)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->cmd = ft_strdup(argv[0]);
	node->argv = ft_strarrdup(argv);
	node->next = NULL;
	return (node);
}
