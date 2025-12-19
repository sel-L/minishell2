/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:30:46 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/19 11:33:42 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "tokenizer.h"
# include "m_env.h"
// # include "builtin.h"

typedef struct	s_node
{
	char			*cmd;
	char			**argv;
	struct s_node	*next;
}				t_node;

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
	struct s_redir	*next;
}					t_redir;

typedef struct s_ast
{
	t_token_type	type;
	char			**argv;
	struct s_redir	*redir;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

int		validator(t_token *token);
char	**tok_to_argv(t_token *token);
int		tok_size(t_token *token);
void	print_str_arr(char **str_arr);
void	free_argv(char **argv);
char	**ft_2d_append_back(char **ori, char *content);
char	**ft_2d_dup(char **src);
int		is_redir(t_token_type t);
void	garbage_collector(t_parsing	*p, char **argv, char *str);
int		parsing(char *str, t_parsing *parse);
int		ft_readline(t_parsing *p, char *prompt);
void	ft_free_str_arr(char **str);
int		ft_strarr_len(char **str);
char	**ft_strarrdup(char **str);
t_redir	*create_redir_node(char *file_dest, t_token_type type);
void	*append_redir_back(t_redir *redir, t_redir **redir_list);
void	free_redir_list(t_redir *redir);
t_ast	*parse_primary(t_token **token);
t_ast	*build_pipe(t_ast *left, t_ast *right);
void	*free_ast(t_ast *ast);
int		append_args_after_redir(t_ast *ast, t_token **token);
t_ast	*build_ast(t_token **token);
void	print_ast(t_ast *ast, int depth);
t_node	*create_node(char **argv);

#endif
