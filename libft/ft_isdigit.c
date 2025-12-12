/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:10:08 by selow             #+#    #+#             */
/*   Updated: 2025/05/19 21:50:13 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%i\n", ft_isdigit(argv[1][0]));
	
	return 0;
}*/
