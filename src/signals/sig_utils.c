/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 12:54:04 by selow             #+#    #+#             */
/*   Updated: 2026/01/20 17:43:03 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_minishell.h"

// SIGNALS UTILS SECTION ================
// resetting the prompt
void	reset_prompt(int signum)
{
	// (void)signum;
	write(2, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	set_signal(signum);
}

void	reset_prompt_two(int signum)
{
	// (void)signum;
	write(2, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
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

// Handle segmentation fault by exiting with code 139
void	handle_segfault(int signum)
{
	(void)signum;
	ft_putstr_fd("Segmentation fault (core dumped)\n", 2);
	exit(139);
}

// resetting sig to their original action; based on POSIX
// During execution, the child should be responding the DEFAULT signals.
void	reset_sig_to_default(int signum)
{
	struct	sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = SIG_DFL; // RESET SIGNALS TO WORK AS USUAL
	sigaction(signum, &sa, NULL);
	set_signal(signum);
}

// MIGHT BE AN EXTRA FUNCTION ?
// Printing Quit (core dumped)
// void	print_core_dump(int signum)
// {
// 	(void)signum;
// 	ft_putstr_fd("Quit (core dumped)\n", 2);
// 	set_signal(signum);
// }
