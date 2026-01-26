/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:21:57 by selow             #+#    #+#             */
/*   Updated: 2026/01/26 22:09:40 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_minishell.h"
#include <stdbool.h>

static bool	has_n_flag(char *str)
{
	if (!str)
		return (false);
	if (*str != '-')
		return (false);
	str++;
	if (*str == '\0')
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

int	echo(char **argv)
{
	int		i;
	bool	n_flag;

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
	return (0);
}
/*
int main(int argc, char **argv)
{
	echo(argv);
}*/
