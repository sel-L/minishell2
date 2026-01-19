/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 09:30:04 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/17 10:27:52 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_minishell.h"

int	isnumber(char c)
{
	return (c >= '0' || c  <= '9');
}

int	handle_negative_return(int num)
{
	while (num < 0)
		num += 256;
	return (num);
}

int	rvalue(void *input)
{
	static int	return_value;
	int					i;
	char				*str;

	str = (char *)input;
	if (!str)
		return (return_value);
	else
	{
		i = 0;
		while (str[i])
		{
			if (!(isnumber(str[i])))
				return (-1);
			i++;
		}
		return_value = ft_atoi(str);
		if (return_value < 0)
			return_value = handle_negative_return(return_value);
	}
	return (0);
}

