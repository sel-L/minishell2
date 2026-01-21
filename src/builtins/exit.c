/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 02:19:19 by selow             #+#    #+#             */
/*   Updated: 2025/12/20 02:57:01 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_minishell.h"

/*
builtin exit 
-> if any other command is called, do not print quit
-> find exit code

if exit_code not specified:
	exit with 0

Error handling
if exit has too many arguments:
	do not exit
	Change exit_code ($?) to 1
	And print “minishell: exit: too many arguments”

If exit’s arguments has anything that arent numbers
	Print exit
	Change exit_code ($?) to 2
	Print “minishell: exit: <command>: numeric argument required”
	Exit
*/

// checks if a string is completely integer characters, NO SPACES OR ANYTHING
bool	is_num(char *str)
{
	while (*str)
	{
		if (*str < '0' && *str > '9')
			return (false);
		str++;
	}
	return (true);
}

void	exit_minishell_clean(t_parsing *p, int exitcode)
{
	final_cleanup(p);
	exit(exitcode);
}

void	ft_exit(char **argv, int argc, t_parsing *p)
{
	int	exit_code;

	exit_code = rvalue(NULL);
	ft_putstr_fd("exit1\n", 1); // tryna debug BUT WHY IT NO WORK
	if (p->interactive_mode == 1)
		ft_putstr_fd("exit2\n", 1);
	if (argc > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments", 2);
		exit_code = 1;
		rvalue(&exit_code);
	}
	else if (!is_num(argv[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		write(2, argv[1], ft_strlen(argv[1]));
		ft_putstr_fd(": numeric argument required", 2);
		exit_code = 2;
		rvalue(&exit_code);
	}
	exit_minishell_clean(p, rvalue(NULL));
}
