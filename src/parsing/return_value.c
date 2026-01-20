/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 09:30:04 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/20 17:31:52 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

int	handle_negative_return(int num)
{
	while (num < 0)
		num += 256;
	return (num);
}

int	rvalue(int input)
{
	static int	return_value;

	if (input == NULL)
		return (return_value);
	if (return_value < 0)
		return_value = handle_negative_return(return_value);
	else
		return_value = input;
	return (0);
}

