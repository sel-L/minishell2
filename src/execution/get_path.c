/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:08:42 by selow             #+#    #+#             */
/*   Updated: 2026/01/21 16:59:30 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sub_minishell.h"

void	free_all(char **vpd)
{
	int	i;

	if (!vpd)
		return ;
	i = 0;
	while (vpd[i])
		free(vpd[i++]);
	free(vpd);
}

char	**_get_path(char **envp)
{
	int		i;
	
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (ft_split(envp[i] + 5, ':'));
		}
		i++;
	}
	return (NULL);
}

char	*get_path(char	*cmd, char **envp)
{
	char	**v_possible_dir;
	int		i;
	char	*path;
	char	*temp;
	
	v_possible_dir = _get_path(envp);
	if (!v_possible_dir)
		return (NULL);
	i = 0;
	while (v_possible_dir[i])
	{
		temp = ft_strjoin(v_possible_dir[i], "/");
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(path, X_OK) == 0)
		{
			free_all(v_possible_dir);
			return (path);
		}
		free(path);
		i++;
	}
	free_all(v_possible_dir);
	return (cmd);
}
