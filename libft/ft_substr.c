/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 05:17:29 by selow             #+#    #+#             */
/*   Updated: 2025/05/29 16:15:20 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *src, int start, int len)
{
	int		i;
	char	*substr;
	int		slen;

	if (src == NULL)
		return (NULL);
	slen = ft_strlen(src);
	if (start < 0 || start > slen)
		return (ft_strdup(""));
	if ((len + start) > slen)
		len = slen - start;
	i = 0;
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	while (src[start + i] != '\0' && i < len)
	{
		substr[i] = src[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
