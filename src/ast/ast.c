/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:15:15 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/19 10:29:27 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

t_ast	*build_ast(t_token **token)
{
	t_ast	*left;
	t_ast	*pipe;

	if (!token || !*token)
		return (ft_putendl_fd("Build ast: invalid token\n", 2), NULL);
	left = parse_primary(token);
	if (!left)
		return (NULL);
	if (*token && (*token)->type == PIPE)
	{
		*token = (*token)->next;
		if (!*token)
			return (ft_putendl_fd("Syntax error: expected cmd\n", 2),
				free_ast(left), NULL);
		pipe = build_pipe(left, build_ast(token));
		if (!pipe)
			return (NULL);
		return (pipe);
	}
	return (left);
}
