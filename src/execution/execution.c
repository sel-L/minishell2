/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 02:21:44 by selow             #+#    #+#             */
/*   Updated: 2026/01/19 23:05:50 by wshou-xi         ###   ########.fr       */
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
	pid_t	left;
	pid_t	right;
	int		status;

	pipe(fd);
	left = fork();
	if (left == 0)
		exit(exec_child(node->left, env, fd, STDOUT_FILENO));
	right = fork();
	if (right == 0)
		exit(exec_child(node->right, env, fd, STDIN_FILENO));
	close(fd[0]);
	close(fd[1]);
	waitpid(left, &status, 0);
	waitpid(right, &status, 0);
	if (WIFEXITED(status))
	 	return (WEXITSTATUS(status));
	return (0);
}
// ===================================================

// ==== EXECUTING A SINGLE COMMAND SECTION ===========
// HELPER for exec_cmd
// Checks if the string passed in is already a valid path
// Valid path = executable (X_OK)
static bool	is_alr_path(char *path)
{
	if (access(path, X_OK) == 0)
		return (true);
	return (false);
}

// Executes a given command (an AST node) in a child process
// Returns the child's exit status
int exec_cmd(t_ast *node, char **env)
{
	pid_t	pid;
	int		status;
	char	*path;

    pid = fork();
    if (pid == 0)
    {
        apply_redirections(node->redir);
		if (is_builtin(node->argv[0]))
			builtin(node->argv[0], get_parsing_struct(NULL));
		else if (!is_alr_path(node->argv[0]))
			path = get_path(node->argv[0], env);
		else
			path = node->argv[0];
		if (execve(path, node->argv, env) == -1)
		{
			if (errno == ENOENT)
				error_msg_exit(node->argv[0], "command not found\n", 127);
			else
				error_msg_exit(node->argv[0], "Permission denied\n", 126);
		}
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
// ===================================================================
