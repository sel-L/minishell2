/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:02:15 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/02/08 22:31:35 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

#include "main_minishell.h"

int	is_builtin(char	**argv)
{
	if (!argv || !argv[0] || !argv[0][0])
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

void	print_invalid_argv(char *cmd)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": too many arguments", 2);
}

int	builtin(char **argv, t_parsing *p)
{
	int	exit_code;

	if (!argv || !argv[0])
		return (0);
	if ((ft_strcmp(argv[0], "pwd") == 0))
		exit_code = pwd();
	else if ((ft_strcmp(argv[0], "cd") == 0) && (argument_count(argv) <= 2))
		exit_code = cd(argv[1], p);
	else if (ft_strcmp(argv[0], "export") == 0)
		exit_code = ft_export(&p->env_list, argv);
	else if (ft_strcmp(argv[0], "unset") == 0)
		exit_code = unset(argv[1], &p->env_list);
	else if ((ft_strcmp(argv[0], "env") == 0) && (argument_count(argv) == 1))
		exit_code = env(&p->env_list);
	else if (ft_strcmp(argv[0], "echo") == 0)
		exit_code = echo(argv);
	else if (ft_strcmp(argv[0], "exit") == 0)
		exit_code = ft_exit(argv, argument_count(argv), p);
	else
	{
		print_invalid_argv();
		exit_code = 1;
	}
	return (rvalue(&exit_code));
}

void	change_path(t_parsing *p, char *path)
{
	char	*oldpath;

	oldpath = get_curr_path();
	change_key_value("OLDPWD", oldpath, &p->env_list);
	chdir(path);
	change_key_value("PWD", path, &p->env_list);
	free(path);
	free(oldpath);
}
