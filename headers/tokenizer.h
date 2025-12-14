/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:20:01 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/14 17:02:08 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_h

# include "minishell.h"

struct s_token_data
{
	int	d_quote;
	int	s_quote;
}	t_token_data;

typedef enum	e_token_type
{
	WORD,
	PIPE,
	R_IN,
	R_OUT,
	APPEND,
	HEREDOC
}				t_token_type;

typedef struct	s_token
{
	char			*value;
	t_token_type	type;
	struct	s_token	*next;
}	t_token;



t_token	*add_and_append_token(t_token **list, t_token_type type, char *token);

#endif