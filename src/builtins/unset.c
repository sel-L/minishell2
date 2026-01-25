/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:22:40 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/25 16:53:44 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "parsing.h"
#include "main_minishell.h"

int	unset(char *target, t_env_list **env)
{
	if (!target || !env || !*env)
		return (1);
	if (target[0] == '$')
		return (1);
	remove_env(target, env);
	return (0);
}
