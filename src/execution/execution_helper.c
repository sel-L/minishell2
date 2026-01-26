/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 09:27:48 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/26 23:43:43 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

void	close_and_waitpid(int fd, pid_t pid, int *status)
{
	close(fd);
	waitpid(pid, status, 0);
}

int	exec_builtin(t_ast *node)
{
	int	fd[2];
	int	exit_code;

	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	apply_redirections(node->parsing, node->redir);
	exit_code = builtin(node->argv, node->parsing);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	return (exit_code);
}

// HELPER for exec_cmd
// Checks if the string passed in is already a valid path
// Valid path = executable (X_OK)
bool	is_alr_path(char *path)
{
	if (access(path, X_OK) == 0)
		return (true);
	return (false);
}

void	exec_external_child(t_ast *node, char **env)
{
	char	*path;

	apply_redirections(node->parsing, node->redir);
	if (!node->argv || !node->argv[0] || node->argv[0][0] == '\0')
		clean_child_exit(node, env, NULL, 0);
	if (!is_alr_path(node->argv[0]))
		path = get_path(node->argv[0], env);
	else
		path = node->argv[0];
	if (execve(path, node->argv, env) == -1)
	{
		if (errno == ENOENT)
			clean_child_exit(node, env, path, 127);
		clean_child_exit(node, env, path, 126);
	}
}
