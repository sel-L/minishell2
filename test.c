/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:19:34 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/14 16:48:41 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>

int	quote_size(char *str, int i)
{
	int	s_quote;
	int	d_quote;

	if (!str)
		return (-1);
	s_quote = 0;
	d_quote = 0;
	if (str[i] == '\'')
		s_quote = 1;
	if (str[i] == '"')
		d_quote = 1;
	i++;
	while(str[i])
	{
		if (str[i] == '"' && d_quote)
			break ;
		if (str[i] == '\'' && s_quote)
			break ;
		i++;
	}
	return (i - 1);
}


int	main(void)
{
	int	size;
	char	*av;

	av = readline("> ");
	printf("av is %s\n", av);
	size = quote_size(av, 0);
	printf("quote size is %d\n", size);
	return (0);
}