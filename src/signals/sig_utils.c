/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:54:04 by selow             #+#    #+#             */
/*   Updated: 2025/12/12 12:54:05 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_minishell.h"

// SIGNALS UTILS SECTION ================
// resetting the prompt
static void	reset_prompt(int signum)
{
	(void)signum;
	write(2, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	set_signal(signum);
}

// To set what signal was received to g_signal global variable.
void	set_signal(int signum)
{
	if (signum == SIGINT)
		g_signal = SIGINT;
	else if (signum == SIGQUIT)
		g_signal = SIGQUIT;
}

// resetting sig to their original action; based on POSIX
void	reset_sig_to_default(int signum)
{
	struct	sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = SIG_DFL; // RESET SIGNALS TO WORK AS USUAL
	sigaction(signum, &sa, NULL);
	set_signal(signum);
}

// Printing Quit (core dumped)
void	print_core_dump(int signum)
{
	(void)signum;
	ft_putstr_fd("Quit (core dumped)\n", 2);
	set_signal(signum);
}
