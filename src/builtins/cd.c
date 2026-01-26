/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:22:06 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/26 22:09:12 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

char	*get_curr_path();

int	check_absolute(char *path)
{
	if (!path || !path[0])
		return (0);
	return (path[0] == '/');
}

int	validate_path(char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (!dir)
		return (0);
	closedir(dir);
	return (1);
}

char	*find_path(char *path)
{
	char	*curr_path;
	char	*res;
	char	*temp;

	if (check_absolute(path))
	{
		if (!validate_path(path))
			return (perror("cd"), NULL);
		return (ft_strdup(path));
	}
	curr_path = get_curr_path();
	if (!curr_path)
		return (NULL);
	temp = ft_strjoin(curr_path, "/");
	free(curr_path);
	res = ft_strjoin(temp, path);
	free(temp);
	if (!validate_path(res))
		return (free(res), NULL);
	return (res);
}

char	*get_curr_path(void)
{
	char	*currpwd;

	currpwd = getcwd(NULL, 0);
	if (!currpwd)
		return (NULL);
	return (currpwd);
}

int	cd(char *h_path, t_parsing *p)
{
	char		*path;
	int			flag;
	t_env_list	*env;

	flag = 0;
	env = p->env_list;
	if (!h_path && !find_env_key("HOME", &env))
		return (ft_putendl_fd("cd: home not set", 2), 1);
	else if (!h_path)
	{
		h_path = get_value("HOME", &env);
		flag = 1;
	}
	path = find_path(h_path);
	if (!path)
		return (ft_putendl_fd("cd: No such file or directory", 2), 1);
	change_path(p, path);
	if (flag == 1)
		free(h_path);
	return (0);
}
