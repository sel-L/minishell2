/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:15:15 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/04 13:23:17 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
// #include "parsing.h"
#include "main_minishell.h"

t_ast	*ast(t_token **token)
{
	t_ast	*ast;
	t_token	*head;

	head = *token;
	ast = build_ast(token);
	*token = head;
	return (ast);
}

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

void	print_redir(t_redir *redir, int	depth)
{
	int	i;

	while (redir)
	{
		i = 0;
		while(i < depth)
		{
			printf("  ");
			i++;
		}
		if (redir->type == REDIR_IN)
			printf("< %s\n", redir->file);
		else if (redir->type == REDIR_OUT)
			printf("> %s\n", redir->file);
		else if (redir->type == HERE_DOC)
			printf("<< %s\n", redir->file);
		else if (redir->type == APPEND)
			printf(">> %s\n", redir->file);
		redir = redir->next;
	}
}

void	print_ast(t_ast *ast, int depth)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		printf("  ");
		i++;
	}
	if (ast->type == PIPE)
	{
		printf("Pipe\n");
		print_ast(ast->left, depth + 1);
		print_ast(ast->right, depth + 1);
	}
	else if (ast->type == CMD)
	{
		printf("CMD: \n");
		print_str_arr(ast->argv);
		if (ast->redir)
			print_redir(ast->redir, depth + 1);
	}
}
