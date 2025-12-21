/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 02:21:44 by selow             #+#    #+#             */
/*   Updated: 2025/12/17 03:06:18 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/execution.h"


t_ast_node
{
	t_node_type	type;
	char		**argv; // “echo”, “a”
	t_redir		*redir;
	t_ast_node 	*left;
	t_ast_node 	*right;
}


void	execute(t_ast_node node)
{
    if (!node)
        return (0);
    if (node->type == CMD)
        return exec_cmd(node);
    if (node->type == PIPE)
        return exec_pipe(node);	
}
