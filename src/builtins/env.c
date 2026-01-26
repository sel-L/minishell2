/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:22:18 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/26 22:10:00 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "parsing.h"
#include "main_minishell.h"

int	env(t_env_list **env)
{
	if (!env || !*env)
		return (ft_putendl_fd("env: Invalid env", 2), 1);
	print_env(*env);
	return (0);
}
