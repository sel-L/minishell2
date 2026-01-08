/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:27:12 by selow             #+#    #+#             */
/*   Updated: 2025/05/19 21:28:00 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;

	dptr = (unsigned char *)dst;
	sptr = (const unsigned char *)src;
	if (sptr < dptr && dptr < sptr + n)
	{
		while (n--)
			dptr[n] = sptr[n];
	}
	else
	{
		while (n--)
			*dptr++ = *sptr++;
	}
	return (dst);
}
