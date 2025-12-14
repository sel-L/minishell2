/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:26:33 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/11/29 14:20:01 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include <readline/readline.h>

// int	main(int ac, char **av, char **envp)
// {
// 	t_env_list	*env_list;
// 	char		**temp;

// 	(void)ac;
// 	(void)av;
// 	env_list = env_to_list(envp);
// 	temp = list_to_char(&env_list, NULL);
// 	print_arr_str(temp);
// 	// print_env(env_list);
// 	free_env(env_list);
// 	free(temp);
// 	return (0);
// }
