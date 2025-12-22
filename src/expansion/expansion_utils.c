/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:11:02 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/22 17:19:03 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

int	single_quoted(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\'')
		i++;
	return (i);
}

char	*double_quoted(t_parsing *p, char *str)
{
	char	*value;

	value = get_expanded_value(p, str);
	if (*str == '"')
		str++;
	return (value);
}

int	idenfity_quotes(char *str)
{
	if (*str == '\'')
		return (1);
	else if (*str == '"')
		return (2);
}
