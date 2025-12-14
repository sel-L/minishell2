/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:22:40 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/14 13:22:42 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	unset(char *target, t_env_list **env)
{
	if (!target || !env || !*env)
		return ;
	if (target[0] == '$')
		return ;
	remove_env(target, env);
	return ;
}
