/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 00:02:16 by wee               #+#    #+#             */
/*   Updated: 2025/12/18 11:01:34 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "parsing.h"
# include "minishell.h"
# include "m_env.h"
# include <dirent.h>

typedef struct s_parsing	t_parsing;
typedef struct s_env_list	t_env_list;

void	pwd(void);
void	cd(char *h_path, t_parsing *p);
void	ls(char *path);
void	*export(t_env_list **env, char **arg);
void	unset(char *target, t_env_list **env);
void	env(t_env_list **env);
int		is_builtin(char	**argv);
void	builtin(char **argv, t_parsing *p);

#endif