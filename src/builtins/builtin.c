/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:02:15 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/26 15:46:12 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include "main_minishell.h"

int	is_builtin(char	**argv)
{
	return (ft_strcmp(argv[0], "pwd") == 0
		|| ft_strcmp(argv[0], "cd") == 0
		|| ft_strcmp(argv[0], "export") == 0
		|| ft_strcmp(argv[0], "exit") == 0
		|| ft_strcmp(argv[0], "unset") == 0
		|| ft_strcmp(argv[0], "env") == 0
		|| ft_strcmp(argv[0], "echo") == 0);
}

void	builtin(char **argv, t_parsing *p)
{
	if (ft_strcmp(argv[0], "pwd") == 0)
		pwd();
	if (ft_strcmp(argv[0], "cd") == 0)
		cd(argv[1], p);
	if (ft_strcmp(argv[0], "export") == 0)
		ft_export(&p->env_list, argv);
	if (ft_strcmp(argv[0], "unset") == 0)
		unset(argv[1], &p->env_list);
	if (ft_strcmp(argv[0], "env") == 0)
		env(&p->env_list);
}
