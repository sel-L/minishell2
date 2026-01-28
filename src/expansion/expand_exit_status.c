/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_exit_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 05:48:42 by selow             #+#    #+#             */
/*   Updated: 2026/01/29 05:48:43 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

char	*expand_exit_status(char *var_name, int *i)
{
	int		return_val;
	char	*res;

	return_val = rvalue(NULL);
	res = ft_itoa(return_val);
	if (!res)
		res = ft_strdup("0");
	*i += ft_strlen(var_name);
	return (res);
}
