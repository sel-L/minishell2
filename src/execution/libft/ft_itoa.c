/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:29:53 by selow             #+#    #+#             */
/*   Updated: 2025/05/19 19:14:54 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits_and_neg(long n)
{
	int	ndigits;

	ndigits = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
	{
		ndigits += 1;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		ndigits += 1;
	}
	return (ndigits);
}

static char	*ft_parse(long num, char *new, int len)
{
	if (num == 0)
	{
		new[len] = '0';
		return (new);
	}
	if (num < 0)
	{
		new[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		new[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (new);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		len;
	long	num;

	len = ft_count_digits_and_neg(n);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	num = (long)n;
	new[len--] = '\0';
	return (ft_parse(num, new, len));
}

/*
	Error: Nested parentheses, braces or brackets are not correctly closed
*/
