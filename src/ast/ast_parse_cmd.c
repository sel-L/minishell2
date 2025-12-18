/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_parse_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:15:12 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/18 19:40:50 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parsing.h"

t_ast	*parse_primary(t_token **token)
{
	
}

t_redir	*build_redir(t_token **token)
{
	char	*file_name;

	while (*)
}

char	**build_arg(t_token **token)
{
	char	**arg;
	int		size;
	int		i;

	count = 0;
	while (*token && (*token)->type == WORD)
	{
		size++;
		*token = (*token)->next;
	}
	arg = malloc(sizeof(char *) * (size + 1));
	if (!arg)
		return (ft_putendl_fd("Build arg: malloc failed", 2));
	i = 0;
	while(i < size)
	{
		arg[i] = ft_strdup((*token)->value);
		i++;
		*token = (*token)->next;
	}
	argv[i] = NULL;
	
}
