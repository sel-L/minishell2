/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 06:32:14 by selow             #+#    #+#             */
/*   Updated: 2025/05/19 21:39:48 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		target;

	i = 0;
	str = (const unsigned char *)s;
	target = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == target)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
