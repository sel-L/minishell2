/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 06:43:29 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/02/03 16:57:25 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

static int	event(void)
{
	if (g_signal == SIGINT)
		rl_done = 1;
	return (0);
}

void	print_warning(int line_count, char *delim)
{
	char	*str;

	ft_putstr_fd("warning: here-document at line ", 2);
	str = ft_itoa(line_count);
	ft_putstr_fd(str, 2);
	free(str);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(delim, 2);
	ft_putendl_fd("')", 2);
}

int	read_loop(int fd, char *delim, int line)
{
	char	*buf;

	rl_event_hook = event;
	while (1)
	{
		buf = readline("heredoc> ");
		if (g_signal == SIGINT)
		{
			rl_event_hook = NULL;
			return (free(buf), -1);
		}
		if (!buf)
			return (print_warning(line, delim), 0);
		if (ft_strcmp(buf, delim) == 0)
			return (free(buf), 0);
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
		free(buf);
		line++;
	}
	return (0);
}

int	heredoc(t_parsing *p, char *delim)
{
	int		fd[2];
	int		line;

	if (pipe(fd) == -1)
		return (perror("pipe"), -1);
	if (p)
		line = p->line_count;
	else
		line = 0;
	if (read_loop(fd[1], delim, line) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	close(fd[1]);
	rl_event_hook = NULL;
	return (fd[0]);
}
