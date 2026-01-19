/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:46:09 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/20 00:11:15 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../headers/parsing.h"
#include "main_minishell.h"

void	free_argv(char **argv)
{
	int	i;

	if (!argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	return ;
}

int	tok_size(t_token *token)
{
	t_token	*temp;
	int		i;

	if (!token)
		return (-1);
	temp = token;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

char	**tok_to_argv(t_token *token)
{
	int		size;
	int		i;
	char	**res;
	t_token	*temp;

	if (!token)
		return (NULL);
	temp = token;
	size = tok_size(token);
	res = malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = ft_strdup(temp->value);
		i++;
		temp = temp->next;
	}
	res[i] = NULL;
	return (res);
}

void	print_str_arr(char **str_arr)
{
	int	i;

	if (!str_arr || !*str_arr)
		return ;
	i = 0;
	while (str_arr[i])
	{
		printf("[\"%s\"] ", str_arr[i]);
		i++;
	}
	printf("\n");
	return ;
}
