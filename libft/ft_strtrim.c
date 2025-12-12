/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 20:12:03 by selow             #+#    #+#             */
/*   Updated: 2025/05/19 22:56:43 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*_tab(char const *s1, char const *set, size_t start, size_t end)
{
	int	hashmap[256];

	ft_bzero(hashmap, sizeof(hashmap));
	while (*set)
		hashmap[(unsigned char)*set++] = 1;
	while (s1[start] && hashmap[(unsigned char)s1[start]] == 1)
		start++;
	while (end > start && hashmap[(unsigned char)s1[end - 1]] == 1)
		end--;
	return (ft_substr(s1, start, end - start));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (ft_strdup(""));
	if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	if (end * ft_strlen(set) > 1000)
		return (_tab(s1, set, start, end));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}

/*
	DESCRIPTION :
	The function ft_strtrim removes any characters of the given set from
	the beginning and end of the given string s1, and allocates sufficient
	memory to store the trimmed copy of the string.

	RETURN VALUE :
	A pointer to the trimmed copy of the string.
	NULL if the memory allocation fails.
*/
