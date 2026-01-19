/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:02:33 by selow             #+#    #+#             */
/*   Updated: 2026/01/19 23:06:17 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_minishell.h"

/*
typedef struct	s_redir
{
	t_token_type	type;
	char			*file;
	struct s_redir	*next;
}					t_redir;
*/

// opens and dup2 a file into their corresponding fds
// serves nothing special other than a line saver, 
// due to apply_redirection() being too long WHYYY (LMAO)
static void	open_dup(char *file, int flags)
{
	int	fd;

	if (flags == O_RDONLY)
	{
		fd = open(file, flags);
		if (fd < 0)
			error_msg_exit(file, "No such file or directory\n", 1);
		dup2(fd, STDIN_FILENO);
		close(fd);
		return ;
	}
	fd = open(file, flags, 0644);
	if (fd < 0)
		error_msg_exit(file, "Permission denied\n", 126);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

// Opens files according to the filetypes (redir->type)
// Dup2 them accordingly for exec_cmd to pass on to the correct pipe
void	apply_redirections(t_redir *redir)
{
	while (redir)
	{
		if (redir->type == REDIR_IN)
			open_dup(redir->file, O_RDONLY);
		else if (redir->type == REDIR_OUT)
			open_dup(redir->file, O_WRONLY | O_CREAT | O_TRUNC);
		else if (redir->type == APPEND)
			open_dup(redir->file, O_WRONLY | O_CREAT | O_APPEND);
		redir = redir->next;
	}
}
