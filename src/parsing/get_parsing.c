/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 21:21:05 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/21 15:14:32 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

t_parsing	*get_parsing_struct(t_parsing **p)
{
	static t_parsing	**parsing;

	if (!p && (!parsing || !*parsing))
		return (ft_putendl_fd(("get_parsing_struct: failed"), 2), NULL);
	if (!p)
		return (*parsing);
	else
		parsing = p;
	return (NULL);
}
