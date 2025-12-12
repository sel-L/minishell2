/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 02:42:07 by selow             #+#    #+#             */
/*   Updated: 2025/05/19 21:08:35 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	slen;

	if (src == NULL)
		return (0);
	slen = ft_strlen(src);
	if (dsize == 0)
		return (slen);
	while (*src != '\0' && dsize - 1 > 0)
	{
		*dst++ = *src++;
		dsize--;
	}
	*dst = '\0';
	return (slen);
}
