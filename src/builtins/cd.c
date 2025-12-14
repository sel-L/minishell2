/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:26:01 by joloo             #+#    #+#             */
/*   Updated: 2025/12/11 19:12:38 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

char *get_curr_path();

int check_absolute(char *path)
{
	if (!path || !path[0])
		return (0);
	return (path[0] == '/');
}

int validate_path(char *path)
{
	DIR *dir;

	dir = opendir(path);
	if (!dir)
		return (0);
	closedir(dir);
	return (1);
}

char *find_path(char *path)
{
	char *curr_path;
	char *res;
	char *temp;

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

char *get_curr_path()
{
	char *currpwd;

	currpwd = getcwd(NULL, 0);
	if (!currpwd)
		return (NULL);
	return (currpwd);
}

void cd(char *h_path, t_parsing *p)
{
	char		*path;
	char		*oldpath;
	int			flag;
	t_env_list	*env;

	flag = 0;
	env = p->env_list;
	if (!h_path && !find_env_key("HOME", &env))
		return (perror("HOME not set"));
	else if (!h_path)
	{
		h_path = get_value("HOME", &env);
		flag = 1;
	}
	path = find_path(h_path);
	if (!path)
		return (perror("path not found"));
	oldpath = get_curr_path();
	change_key_value("OLDPWD", oldpath, &env);
	chdir(path);
	change_key_value("PWD", path, &env);
	free(path);
	free(oldpath);
	if (flag == 1)
		free(h_path);
}

void ls(char *path)
{
	DIR				*dir;
	char			*c_path;
	struct dirent	*entry;

	c_path = find_path(path);
	if (!c_path)
		return (free(c_path));
	dir = opendir(c_path);
	while ((entry = readdir(dir)) != NULL)
		printf("%s  ", entry->d_name);
	printf("\n");
	free(c_path);
	closedir(dir);
}
