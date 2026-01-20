/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:00:11 by selow             #+#    #+#             */
/*   Updated: 2026/01/08 17:00:13 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_minishell.h"

// Prints an error message to the STDERROR and exits.
// e.g. 
// minishell: fdgfsfad: command not found
// exit_code = 127
void	error_msg_exit(char *target, char *msg, int exit_code)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(target, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	exit(exit_code);
}
