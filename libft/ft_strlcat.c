/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:46:02 by selow             #+#    #+#             */
/*   Updated: 2025/05/19 21:09:59 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dsize <= dlen)
		return (dsize + slen);
	i = 0;
	while (src[i] != '\0' && (dlen + i + 1) < dsize)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
/*
copy   
This term is used when the writing starts at the first  
element pointed to by dst.

catenate
This  term is used when a function first finds the terminat‐
ing null character in dst, and then starts writing  at  that
position
*/
