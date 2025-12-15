/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:30:46 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/12/15 17:32:54 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"
# include "tokenizer.h"
# include "m_env.h"
# include "builtin.h"


typedef struct	s_parsing
{
	t_env_list	*env_list;
	t_token		*token;
}				t_parsing;

typedef struct	s_redir
{
	int				fd;
	t_token_type	type;
	char			*value;
	struct s_node	*next;
}					t_redir;

typedef struct s_cmd
{
	pid_t	pid;
	t_token	*words; // word tokens
	t_redir	*redir_in; // < <<
	t_redir	*redir_out; // > >>
	int		infile; // final infile to dup2
	int		outfile; // final infile to dup2
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	t_cmd		*cmds;
	int			cmd_count;
	t_env_list	**env;
}				t_data;

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

#endif
