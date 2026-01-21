/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_minishell.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 00:17:21 by wshou-xi          #+#    #+#             */
/*   Updated: 2026/01/21 18:33:43 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_MINISHELL_H
# define MAIN_MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <fcntl.h>
# include <limits.h>
# include <dirent.h>
# include <signal.h>
# include "../libft/libft.h"
# include "../libft/gnl/get_next_line.h"

typedef struct s_parsing t_parsing;

typedef enum	e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	APPEND,
	HERE_DOC,
	CMD
}				t_token_type;

typedef struct	s_env_list
{
	char				*front;
	char				*env_val;
	struct s_env_list	*next;
	struct s_env_list	*prev;
}	t_env_list;

typedef struct s_ast
{
	t_token_type	type;
	t_parsing		*parsing;
	struct s_redir	*redir;
	struct s_ast	*left;
	struct s_ast	*right;
	char			**argv;
}	t_ast;

typedef struct	s_node
{
	char			*cmd;
	char			**argv;
	struct s_node	*next;
}				t_node;

typedef struct	s_redir
{
	t_token_type	type;
	char			*file;
	struct s_redir	*next;
}					t_redir;

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

typedef struct	s_parsing
{
	t_env_list	*env_list;
	t_token		*token;
	t_ast		*ast;
	char		**internal_env;
	int			line_count;
}				t_parsing;

// AST functions
void	*free_ast(t_ast *ast);
t_ast	*build_ast(t_token **token);
t_ast	*ast(t_token **token);
void	print_ast(t_ast *ast, int depth);

// Builtin functions
void	pwd(void);
void	cd(char *h_path, t_parsing *p);
void	*ft_export(t_env_list **env, char **arg);
void	unset(char *target, t_env_list **env);
void	env(t_env_list **env);
int		is_builtin(char	**argv);
void	builtin(char **argv, t_parsing *p);

// Env functions
t_env_list	*find_env_key(char *to_find, t_env_list **list);
t_env_list	*env_to_list(char **env);
void		free_env(t_env_list **env_list);
char		*get_value(char *key, t_env_list **list);
int			change_key_value(char *key, char *value, t_env_list **env);
int			add_env(char *env, t_env_list **list);
int			remove_env(char *target, t_env_list **list);
void		print_env(t_env_list *env);

// Parsing functions
t_parsing	*get_parsing_struct(t_parsing **p);
int			validator(t_token *token);
char		**tok_to_argv(t_token *token);
void		free_argv(char **argv);
int			is_redir(t_token_type t);
void		garbage_collector(t_parsing	*p, char **argv, char *str);
int			parse(char *str, t_parsing *parse);
int			ft_readline(t_parsing *p, char *prompt);
void		final_cleanup(t_parsing *p);
int			rvalue(void *input);

// Tokenizer function
t_token	*tokenizer(char *input);
t_lexer	*init_lex(char *input);
void	free_token_list(t_token *list);
void	print_token_list(t_token **token);

// Expansion functions
char	*expand_and_remove_quotes(char *str, t_parsing *p);
void	process_ast_expansion(t_ast *node, t_parsing *p);
char	*expansion(char *str, t_parsing *p);
char	*get_expanded_value(t_parsing *p, char *str);
void	*expandable(char *str, int *flag);
char	*quote_remover(char *str);

// Heredoc
int	heredoc(t_parsing *p, char *delim);

// Expansion helper function
char	*ft_charjoin(char *str, char chr);
char	*extract_expandable(char *str);
void	update_quote_state(char c, char *quote);
char	*ft_strjoin_then_free(char *s1, char *s2);

// Env helper functions
t_env_list	**delete_node(t_env_list **list);
int			change_value(char *src, t_env_list **list);
int			add_env_node(t_env_list *node ,t_env_list **list);
int			env_size(t_env_list **list);
char		**list_to_char(t_env_list **list, char **res);
int			key_value_len(char *key, t_env_list **list);
void		*print_int_env(char **int_env);
char		**add_int_env(char *target, char *value, char **list);
char		*find_int_env(char *target, char **list);
char		*get_int_env(char *target, char **list);
t_env_list	*empty_node(char *arg);

// AST helper functions
t_redir	*create_redir_node(char *file_dest, t_token_type type);
t_ast	*parse_primary(t_token **token);
t_ast	*build_pipe(t_ast *left, t_ast *right);
void	append_redir_back(t_redir *redir, t_redir **redir_list);
void	free_redir_list(t_redir *redir);
int		append_args_after_redir(t_ast *ast, t_token **token);

// Parsing helper functions
t_node	*create_node(char **argv);
int		tok_size(t_token *token);
void	print_str_arr(char **str_arr);
char	**ft_2d_append_back(char **ori, char *content);
void	ft_free_str_arr(char **str);
int		ft_strarr_len(char **str);
char	**ft_strarrdup(char **str);

// Tokenizer helper function
t_token	*add_and_append_token(t_token **list, t_token_type type, char *token);
void	reset_pos(t_lexer *lex);
int		is_op(char c);
void	*create_word_token(t_lexer *lex, t_token **list);
void	*create_op_token(t_lexer *lex, t_token **list);
void	skip_whitespace(t_lexer *lex);
void	free_single_token(t_token *token);
int		ft_isspace(char c);
int		identify_op(char *op);

// global var
extern int g_signal;

// builtins ============================
void	echo(char **argv);
// exit func h e r e

// signal handling ======================
//signals.c
void	setup_sig_interactive(void);
void	setup_sig_non_intereactive(void);
// sig_utils.c
void	reset_prompt(int signum);
void	set_signal(int signum);
void	reset_sig_to_default(int signum);
void	print_core_dump(int signum);
// sig_ignore.c
void	ignore_all_signals(void);
void	ignore_sig(int signum);

// execution =============================
int		exec_pipe(t_ast *node, char **env);
int		execute(t_ast *node, char **env);
int		exec_cmd(t_ast *node, char **env);
void	clean_child_exit(t_ast *node, char **env, char *path, int exitcode);
void	error_msg(char *target, char *msg);
// apply_redir
void apply_redirections(t_parsing *p, t_redir *redir);
// get_path
char	*get_path(char	*cmd, char **envp);
// error handling
void	error_msg_exit(char *target, char *msg, int exit_code);

#endif