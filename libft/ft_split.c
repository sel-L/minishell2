/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 22:17:15 by selow             #+#    #+#             */
/*   Updated: 2025/05/26 12:47:25 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_free_all(char **new)
{
	int	i;

	i = 0;
	while (new[i])
		free(new[i++]);
	free(new);
	return (NULL);
}

static int	ft_count_words(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		count += 1;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static	int	ft_count_wordlen(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**_fillnew(char **new, const char *s, char c)
{
	int	i;
	int	j;
	int	wordlen;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		wordlen = ft_count_wordlen((char *)s, c);
		new[i] = malloc(sizeof(char) * (wordlen + 1));
		if (new[i] == NULL)
			return (ft_free_all(new));
		j = 0;
		while (*s != c && *s)
			new[i][j++] = *s++;
		new[i][j] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}

char	**ft_split(const char *s, char c)
{
	char	**new;
	int		wordcount;

	if (!s)
		return (NULL);
	wordcount = ft_count_words((char *)s, c);
	new = malloc(sizeof(char *) * (wordcount + 1));
	if (new == NULL)
		return (NULL);
	return (_fillnew(new, s, c));
}
