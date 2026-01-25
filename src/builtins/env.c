/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:22:18 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/14 13:22:21 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "parsing.h"
#include "main_minishell.h"

void	env(t_env_list **env)
{
	if (!env || !*env)
		perror("Env error\n");
	print_env(*env);
}