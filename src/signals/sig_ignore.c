/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_ign.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 23:01:43 by selow             #+#    #+#             */
/*   Updated: 2025/12/12 23:01:48 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_minishell.h"
// IGNORING SIGNALS SECTION ==============
// IGNORES BOTH SIGQUIT AND SIGINT
// During execution, the parent should be ignoring all signals
void	ignore_all_signals(void)
{
	ignore_sig(SIGQUIT);
	ignore_sig(SIGINT);
}

// ignores the signal passed in
void	ignore_sig(int signum)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(struct sigaction));
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = SIG_IGN;
	sigaction(signum, &sa, NULL);
	set_signal(signum);
}
