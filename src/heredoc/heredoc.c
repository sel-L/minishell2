/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 06:43:29 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/22 15:15:42 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

void	*write_buffer_to_pipe(int pipe_write ,char *buffer)
{
	int		size;

	if (!buffer)
		return (NULL);
	size = ft_strlen(buffer);
	write(pipe_write, buffer, size);
	write(1, "\n", 1);
}

void	print_heredoc_warning(int line_count, char *delim)
{
	char	*line_str;

	ft_putendl_fd("warning: here-document at line ", 2);
	line_str = ft_itoa(line_count);
	ft_putstr_fd(line_str, 2);
	free(line_str);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(delim, 2);
	ft_putendl_fd("')", 2);
}

void	*heredoc_loop(t_parsing *p, int *pipefd, char *delimiter)
{
	char		*buffer;
	int			line_count;

	line_count = p->line_count;
	while (1)
	{
		buffer = readline("> ");
		if (!buffer)
			return (print_heredoc_warning(line_count, delimiter), NULL);
		if (ft_strcmp(buffer, delimiter) == 0)
			return (free(buffer), NULL);
		write_buffer_to_pipe(pipefd[1], buffer);
		free(buffer);
		line_count++;
	}
	p->line_count += line_count;
}

int	heredoc(t_parsing *p, char *delim)
{
	int		pipefd[2];
	int		status;
	pid_t	pid;

	if (pipe(pipefd) == -1)
		return (perror("pipe"), -1);
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		heredoc_loop(p, pipefd, delim);
		close(pipefd[1]);
		exit(0);
	}
	else if (pid > 0)
	{
		close(pipefd[1]);
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WIFEXITED(status) != 0)
			return (close(pipefd[0]), -1);
		return (pipefd[0]);
	}
}
