/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:15:12 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/01 15:22:40 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
// #include "parsing.h"
#include "main_minishell.h"

char	**build_arg(t_token **token);
t_redir	*build_redir(t_redir **redir, t_token **token);

void	*free_ast(t_ast *ast)
{
	if (!ast)
		return (NULL);
	if (ast->argv)
		ft_free_str_arr(ast->argv);
	if (ast->redir)
		free_redir_list(ast->redir);
	if (ast->left)
		free_ast(ast->left);
	if (ast->right)
		free_ast(ast->right);
	free(ast);
	return (NULL);
}

t_ast	*build_pipe(t_ast *left, t_ast *right)
{
	t_ast	*pipe;

	if (!left || !right)
		return (free_ast(left), free_ast(right), NULL);
	pipe = malloc(sizeof(t_ast));
	if (!pipe)
		return (free_ast(left), free_ast(right),
			ft_putendl_fd("Creation pipe node failed\n", 2), NULL);
	*pipe = (t_ast){.type = PIPE, .left = left,
		.right = right, .redir = NULL, .argv = NULL};
	return (pipe);
}

t_ast	*parse_primary(t_token **token)
{
	t_ast		*ast_node;
	t_redir		*redir;

	if (!token || !*token)
		return (ft_putendl_fd("Parse primary: Invalid token\n", 2), NULL);
	ast_node = malloc(sizeof(t_ast));
	if (!ast_node)
		return (ft_putendl_fd("Parse primary: Malloc failed", 2), NULL);
	redir = NULL;
	ast_node->argv = build_arg(token);
	if (!ast_node->argv)
		return (free(ast_node),
			ft_putendl_fd("Parse primary: build arg failed\n", 2), NULL);
	ast_node->redir = build_redir(&redir, token);
	if (!append_args_after_redir(ast_node, token))
		return (free_ast(ast_node), NULL);
	ast_node->type = CMD;
	ast_node->left = NULL;
	ast_node->right = NULL;
	return (ast_node);
}

t_redir	*build_redir(t_redir **redir, t_token **token)
{
	t_redir	*temp;

	if (!token || !*token)
		return (NULL);
	while (*token && is_redir((*token)->type))
	{
		if (!(*token)->next || (*token)->next->type != WORD)
			return (ft_putendl_fd("Syntax error: expected filename\n", 2),
				NULL);
		temp = create_redir_node((*token)->next->value, (*token)->type);
		if (!temp)
			return (NULL);
		append_redir_back(temp, redir);
		*token = (*token)->next->next;
	}
	return (*redir);
}

char	**build_arg(t_token **token)
{
	t_token	*start;
	char	**arg;
	int		size;
	int		i;

	size = 0;
	start = *token;
	while (*token && (*token)->type == WORD)
	{
		size++;
		*token = (*token)->next;
	}
	*token = start;
	arg = ft_calloc(size + 1, sizeof(char *));
	i = 0;
	while (i < size)
	{
		arg[i] = ft_strdup((*token)->value);
		if (!arg[i])
			return (ft_free_str_arr(arg), NULL);
		*token = (*token)->next;
		i++;
	}
	return (arg);
}
