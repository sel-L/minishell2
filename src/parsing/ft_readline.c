/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 00:26:28 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/01 14:23:27 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include "main_minishell.h"

int	ft_readline(t_parsing *p, char *prompt)
{
	char		*str;
	static int	line_count;

	str = readline(prompt);
	add_history(str);
	// temp exit
	if (ft_strcmp(str, "exit") == 0)
		return (free(str), 1);
	if (str == NULL || *str == '\0' || *str == 32)
		return (free(str), 2);
	line_count++;
	p->line_count = line_count;
	if (parsing(str, p) == 1)
		return (free(str), rl_clear_history(), 1);
	free(str);
	return (0);
}
