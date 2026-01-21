/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:02:15 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/21 15:52:03 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include "main_minishell.h"

int	is_builtin(char	**argv)
{
	if (!argv || !argv[0])
		return (0);
	return (ft_strcmp(argv[0], "pwd") == 0
		|| ft_strcmp(argv[0], "cd") == 0
		|| ft_strcmp(argv[0], "export") == 0
		|| ft_strcmp(argv[0], "exit") == 0
		|| ft_strcmp(argv[0], "unset") == 0
		|| ft_strcmp(argv[0], "env") == 0
		|| ft_strcmp(argv[0], "echo") == 0
		|| ft_strcmp(argv[0], "exit") == 0);
}

int	argument_count(char **argv)
{
	int	i;

	i = 0;
	if (!argv || !*argv)
		return (0);
	while (argv[i])
		i++;
	return (i);
}

void	print_invalid_argv()
{
	ft_putendl_fd("Builtin: Invalid arguments", 2);
}

void	builtin(char **argv, t_parsing *p)
{
	if (!argv || !argv[0])
		return ;
	ft_putstr_fd("Builtin called\n", 2);
	if ((ft_strcmp(argv[0], "pwd") == 0))
		pwd();
	else if ((ft_strcmp(argv[0], "cd") == 0) && (argument_count(argv) == 2))
		cd(argv[1], p);
	else if (ft_strcmp(argv[0], "export") == 0)
		ft_export(&p->env_list, argv);
	else if (ft_strcmp(argv[0], "unset") == 0)
		unset(argv[1], &p->env_list);
	else if ((ft_strcmp(argv[0], "env") == 0) && (argument_count(argv) == 1))
		env(&p->env_list);
	else if (ft_strcmp(argv[0], "echo") == 0)
		echo(argv);
	else if (ft_strcmp(argv[0], "exit") == 0)
		ft_exit(argv, argument_count(argv), p);
	else
		print_invalid_argv();
}
