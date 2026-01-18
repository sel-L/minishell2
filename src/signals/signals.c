/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:14:29 by selow             #+#    #+#             */
/*   Updated: 2025/12/11 10:02:25 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
- Use of global variable to signal what signal has been received
	-> signal = SIG
	e.g CTRL + C will be signal = SIGINT = 2
		CTRL + \ will be signal = SIGQUIT = 3
*/
#include "sub_minishell.h"
int g_signal = 0;
// to be put into main

// waiting for user input signals
void	setup_sig_interactive(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = reset_prompt;
	sigaction(SIGINT, &sa, NULL);
	ignore_sig(SIGQUIT);
}

// no longer waiting for user input signals
// minishell shouldnt react, but the COMMAND (e.g. cat)
// should be the one reacting instead
void	setup_sig_non_intereactive(void)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = reset_prompt;
	sigaction(SIGINT, &sa, NULL);
	ignore_sig(SIGQUIT);
}
