/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:20:01 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/15 16:39:53 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

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

typedef struct s_lexer
{
	char	*lex_start;
	char	*lex_end;
	int		quote;
	int		d_q;
	int		s_q;
	int		op;
}				t_lexer;


t_token	*add_and_append_token(t_token **list, t_token_type type, char *token);
int		ft_isspace(char c);
int		identify_op(char *op);
t_lexer	*init_lex(char *input);
void	reset_pos(t_lexer *lex);
int		is_op(char c);
void	*create_word_token(t_lexer *lex, t_token **list);
void	*create_op_token(t_lexer *lex, t_token **list);
void	skip_whitespace(t_lexer *lex);
void	free_single_token(t_token *token);
void	free_token_list(t_token *list);
void	print_token_list(t_token **token);
t_token	*tokenizer(char *input);

#endif