/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:17:04 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/15 17:06:39 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main()
{
	char	*str;
	t_token	*token;

	while (1)
	{
		str = readline(">	 ");
		add_history(str);
		if (ft_strncmp(str, "exit", 4) == 0)
			break ;
		token = tokenizer(str);
		free(str);
		print_token_list(&token);
		free_token_list(token);
	}
	rl_clear_history();
	free(str);
	return (0);
}
