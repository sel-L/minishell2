/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:30:46 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/18 15:30:01 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "tokenizer.h"
# include "m_env.h"
# include "builtin.h"

typedef enum e_node_type
{
	CMD,
	PIPE
}	t_node_type;

typedef struct	s_parsing
{
	t_env_list	*env_list;
	t_token		*token;
	char		**internal_env;
}				t_parsing;

typedef struct	s_redir
{
	t_token_type	type;
	char			*file;
	struct s_node	*next;
}					t_redir;

typedef struct s_ast
{
	t_node_type		type;
	char			**argv;
	struct t_redir	*redir;
	struct t_ast	*left;
	struct t_ast	*right;
}	t_ast

int		validator(t_token *token);
char	**tok_to_argv(t_token *token);
int		tok_size(t_token *token);
void	print_str_arr(char **str_arr);
void	free_argv(char **argv);
char	**ft_2d_append_back(char **ori, char *content);
char	**ft_2d_dup(char **src);
void	free_node(t_node *node);
int		is_redir(t_token_type t);
t_node	*create_node(char **argv);
void	free_node(t_node *node);
void	free_node_list(t_node *node);
void	print_node(t_node *node);
void	garbage_collector(t_parsing	*p, char **argv, char *str);
int		parsing(char *str, t_parsing *parse);
int		ft_readline(t_parsing *p, char *prompt);
void	ft_free_str_arr(char **str);
int		ft_strarr_len(char **str);
char	**ft_strarrdup(char **str);
t_node	*token_to_node(t_token *token);

#endif
