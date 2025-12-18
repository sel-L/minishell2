/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_internal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:28:55 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/17 17:57:18 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"
#include "m_env.h"

char	*get_int_env(char *target, char **list)
{
	char	*front;
	char	*value;

	if (!list || !*list)
		return (NULL);
	front = *list;
	value = *list;
	while (*value != '=')
		value++;
	front = ft_substr(front, 0, (value - front));
	if (!ft_strcmp(target, front))
		
	value++;
	value = ft_substr(value, 0, ft_strlen(value));
	
}