/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 18:05:51 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/21 18:33:05 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

void	clean_child_exit(t_ast *node, char **env, char *path, int exitcode)
{
	if (path && node && node->argv && node->argv[0] && path != node->argv[0])
		free(path);
	if (env)
		ft_free_str_arr(env);
	if (node && node->parsing)
	{
		node->parsing->internal_env = NULL;
		final_cleanup(node->parsing);
	}
	exit(exitcode);
}