/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:29:30 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/11 17:45:11 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"

void	add_node_back(t_node *src, t_node **node);
t_node	*token_to_node(t_token *token);
void	print_node(t_node *node);

void	create_and_add_node(t_node **node, char **src)
{
	t_node	*temp;

	temp = create_node(src);
	ft_free_str_arr(src);
	add_node_back(temp, node);
}

void	print_node(t_node *node)
{
	t_node	*temp;

	temp = node;
	while(node)
	{
		printf("%s\n", temp->cmd);
		print_str_arr(temp->argv);
		printf("\n");
		node = temp->next;
	}
}

void	add_node_back(t_node *src, t_node **node)
{
	t_node	*temp;

	if (!*node)
	{
		*node = src;
		src->next = NULL;
		return ;
	}
	temp = *node;
	while(temp->next)
		temp = temp->next;
	temp->next = src;
	src->next = NULL;
	return ;
}

t_node	*token_to_node(t_token *token)
{
	t_node			*list;
	char			**temp;

	list = NULL;
	temp = NULL;
	while(token)
	{
		if (token->type == WORD)
			temp = ft_2d_append_back(temp, token->value);
		else if (token->type == PIPE)
		{
			if (temp)
				create_and_add_node(&list, temp);
			temp = NULL;
		}
		token = token->next;
	}
	if (temp)
		create_and_add_node(&list, temp);
	return (list);
}

// int	main()
// {
// 	t_token	*token;
// 	t_node	*node;

// 	token = tokenize("echo -ls | pipe");
// 	node = token_to_node(token);
// 	print_node(node);
// 	free_node_list(node);
// 	return (0);
// }