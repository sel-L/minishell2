/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 02:21:44 by selow             #+#    #+#             */
/*   Updated: 2026/01/27 00:58:59 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_minishell.h"

// ==== main execution function ===============================
// Executes an ast tree recursively
// Parameters: root of ast tree, env list
// Returns: exit code of the last node executed
int	execute(t_ast *node, char **env)
{
	if (!node)
		return (0);
	if (node->parsing && prepare_heredocs(node, node->parsing))
		return (1);
	if (node->type == CMD)
		return (exec_cmd(node, env));
	if (node->type == PIPE)
		return (exec_pipe(node, env));
	return (0);
}
// =============================================================

// ==== EXECUTING A PIPE SECTION ===============================
// HELPER for exec_pipe
// Sets up pipe redirection for one side (stdin or stdout) and executes
static int	exec_child(t_ast *node, char **env, int *fd, int fileno)
{
	dup2(fd[fileno], fileno);
	close(fd[0]);
	close(fd[1]);
	return (execute(node, env));
}

// Returns the last executed node's exit code to execute()
// Takes in an AST pipe node to fork for right and left nodes
int exec_pipe(t_ast *node, char **env)
{
	int		fd[2];
	pid_t	pid[2];
	int		status;

	status = 0;
	pipe(fd);
	pid[0] = fork();
	if (pid[0] == 0)
		clean_child_exit(node->left, env, NULL,
				exec_child(node->left, env, fd, STDOUT_FILENO));
	pid[1] = fork();
	if (pid[1] == 0)
		clean_child_exit(node->right, env, NULL,
				exec_child(node->right, env, fd, STDIN_FILENO));
	close_and_waitpid(fd[0], pid[0], NULL);
	close_and_waitpid(fd[1], pid[1], &status);
	if (WIFEXITED(status))
	 	return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (0);
}
// ===================================================

// ==== EXECUTING A SINGLE COMMAND SECTION ===========

// Executes a given command (an AST node) in a child process
// Returns the child's exit status
int exec_cmd(t_ast *node, char **env)
{
	pid_t	pid;
	int		status;

	if (is_builtin(node->argv))
		return (exec_builtin(node));
	pid = fork();
	if (pid == 0)
		exec_external_child(node, env);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
// ===================================================================

int	prepare_heredocs(t_ast *node, t_parsing *p)
{
	t_redir	*redir;

	if (!node || !p)
		return (0);
	if (node->type == PIPE)
		return (prepare_heredocs(node->left, p)
			|| prepare_heredocs(node->right, p));
	redir = node->redir;
	while (redir)
	{
		if (redir->type == HERE_DOC && redir->heredoc_fd == -1)
		{
			redir->heredoc_fd = heredoc(p, redir->file);
			if (redir->heredoc_fd < 0)
				return (1);
		}
		redir = redir->next;
	}
	return (0);
}
