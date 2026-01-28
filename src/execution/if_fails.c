/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_fails.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 07:42:57 by selow             #+#    #+#             */
/*   Updated: 2026/01/29 07:42:59 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"
// for exit code 126
void	if_fileexists_fail(t_ast *node, char *path, char **env)
{
	struct stat	st;

	if (stat(path, &st) == -1)
		return ;
	if (S_ISDIR(st.st_mode))
		error_msg(node->argv[0], "Is a directory\n");
	else if ((st.st_mode & S_IXUSR) == 0)
		error_msg(node->argv[0], "Permission denied\n");
	clean_exit_extern_child(node, path, env, 126);
}

// for exit code 127
void	if_execve_fail(
	t_ast *node, char *path, char **env, bool is_explicit_path)
{
	if (errno == ENOENT)
	{
		if (is_explicit_path)
			error_msg(node->argv[0], "No such file or directory\n");
		else
			error_msg(node->argv[0], "command not found\n");
		clean_exit_extern_child(node, path, env, 127);
	}
	if (!is_explicit_path && path == node->argv[0])
	{
		error_msg(node->argv[0], "command not found\n");
		clean_exit_extern_child(node, path, env, 127);
	}
	perror("execve failed");
	clean_child_exit(node, env, path, 126);
}
