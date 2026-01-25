/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:02:15 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/25 16:50:19 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"

#include "main_minishell.h"

void	change_path(t_parsing *p, char *path)
{
	char	*oldpath;

	oldpath = get_curr_path();
	change_key_value("OLDPWD", oldpath, p->internal_env);
	chdir(path);
	change_key_value("PWD", path, p->internal_env);
	free(path);
	free(oldpath);
}

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
	int	exit_code;

	if (!argv || !argv[0])
		return ;
	if ((ft_strcmp(argv[0], "pwd") == 0))
		exit_code = pwd();
	else if ((ft_strcmp(argv[0], "cd") == 0) && (argument_count(argv) == 2))
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
		ft_exit(argv, argument_count(argv), p);
	else
	{
		print_invalid_argv();
		exit_code = 1;
	}
	rvalue(&exit_code);
}
