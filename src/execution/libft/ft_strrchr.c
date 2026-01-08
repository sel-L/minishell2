/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 07:21:47 by selow             #+#    #+#             */
/*   Updated: 2025/05/19 21:07:03 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				len;
	unsigned char	find;

	len = ft_strlen(s);
	find = (unsigned char)c;
	while (len >= 0)
	{
		if (s[len] == find)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}

/*
LIBRARY
       Standard C library (libc, -lc)

SYNOPSIS
       #include <string.h>

       char *strchr(const char *s, int c);
       char *strrchr(const char *s, int c);

       #define _GNU_SOURCE          See feature_test_macros(7) 
       #include <string.h>

       char *strchrnul(const char *s, int c);

DESCRIPTION
       The  strchr() function returns a pointer to the first occurrence of
       the character c in the string s.

       The strrchr() function returns a pointer to the last occurrence  of
       the character c in the string s.

       The  strchrnul()  function is like strchr() except that if c is not
       found in s, then it returns a pointer to the null byte at  the  end
       of s, rather than NULL.

       Here  "character"  means  "byte";  these functions do not work with
       wide or multibyte characters.

RETURN VALUE
       The strchr() and  strrchr()  functions  return  a  pointer  to  the
       matched  character or NULL if the character is not found.  The ter‐
       minating null byte is considered part of the string, so that  if  c
       is  specified as '\0', these functions return a pointer to the ter‐
       minator.

       The strchrnul() function returns a pointer to the  matched  charac‐
       ter,  or  a  pointer  to  the  null  byte  at  the  end of s (i.e.,
       s+strlen(s)) if the character is not found.
*/
