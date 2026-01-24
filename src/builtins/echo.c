/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:21:57 by selow             #+#    #+#             */
/*   Updated: 2025/12/29 15:21:59 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_minishell.h"
#include <stdbool.h>

static bool	has_n_flag(char *str)
{
	if (!str)
		return (false);
	if (*str == '-')
		str++;
	else
		return (false);
	while (*str)
	{
		if (*str != 'n')
			return (false);
		str++;
	}
	return (true);
}
/*
- print whatever is passed in
- if -n flag is specified, print without a newline
*/
void	echo(char **argv)
{
	int		i;
	bool	n_flag;
	int 	status;

	i = 1;
	n_flag = has_n_flag(argv[i]);
	if (n_flag)
		i++;
	while (argv[i])
	{
		ft_putstr_fd(argv[i++], 1);
		if (argv[i])
			ft_putchar_fd(' ', 1);
	}
	if (n_flag == false)
		ft_putchar_fd('\n', 1);
	status = 0;
	rvalue(&status);
}
/*
int main(int argc, char **argv)
{
	echo(argv);
}*/
