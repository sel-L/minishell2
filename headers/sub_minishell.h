/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_minishell.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:02:22 by selow             #+#    #+#             */
/*   Updated: 2026/01/21 15:29:36 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUB_MINISHELL_H
# define SUB_MINISHELL_H

# include "main_minishell.h"
# include "stdbool.h"
# include <errno.h>
# include <signal.h>

/*
	To-Do
		-> Test signals with readline etｃ
		-> Add exit func from imac
	BEFORE SUBMISSION
		DELETE:
			execution:
				test_files/
				libft/
				test.c
				Makefile
			signals:
				signals.c -> global variable, shld be placed into main.c
			
*/

typedef struct s_ast t_ast;
typedef struct s_redir t_redir;

// global var
extern int g_signal;

// builtins ============================
int	echo(char **argv);
void	ft_exit(char **argv, int argc, t_parsing *p);

// signal handling ======================
//signals.c
void	setup_sig_interactive(void);
void	setup_sig_non_intereactive(void);
// sig_utils.c
void	reset_prompt(int signum);
void	set_signal(int signum);
void	reset_sig_to_default(int signum);
void	reset_prompt_two(int signum);

// sig_ignore.c
void	ignore_all_signals(void);
void	ignore_sig(int signum);

// execution =============================
int		exec_pipe(t_ast *node, char **env);
int		execute(t_ast *node, char **env);
int		exec_cmd(t_ast *node, char **env);
// apply_redir
void apply_redirections(t_parsing *p, t_redir *redir);
// get_path
char	*get_path(char	*cmd, char **envp);
// error handling
void	error_msg_exit(char *target, char *msg, int exit_code);
void	error_msg(char *target, char *msg);
// free child
void	clean_child_exit(t_ast *node, char **env,  char *path, int exitcode);

#endif