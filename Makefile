# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 10:47:03 by wshou-xi          #+#    #+#              #
#    Updated: 2025/12/29 23:49:07 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iheaders -I./libft
LIB = -lreadline -lhistory -Llibft -lft
RM = rm -rf
VALGRIND = valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes --verbose

MAINDIR = src/parsing
MAINFILES = test.c ft_readline.c redir_check.c garbage_collector.c
MAIN = $(addprefix $(MAINDIR)/, $(MAINFILES))

ARGVDIR = src/argv
ARGVFILES = argv_to_node.c argv_utils.c tok_conv.c
ARGV = $(addprefix $(ARGVDIR)/, $(ARGVFILES))

B_INDIR = src/builtins
B_INFILES = pwd.c cd.c export.c unset.c env.c builtin.c
B_IN = $(addprefix $(B_INDIR)/, $(B_INFILES))

ENVDIR = src/env
ENVFILES = env_init.c env_op.c env_utils.c env_var_utils.c env_vars.c env_internal.c
ENV = $(addprefix $(ENVDIR)/, $(ENVFILES))

TOKENDIR = src/tokenizer
TOKENFILES = tokenizer.c tokenizer_utils.c tokenizer_utils2.c lexer_utils.c
TOKEN = $(addprefix $(TOKENDIR)/, $(TOKENFILES))

ASTDIR = src/ast
ASTFILES = ast.c ast_redir_utils.c ast_parse_cmd.c
AST = $(addprefix $(ASTDIR)/, $(ASTFILES))

EXPDIR = src/expansion
EXPFILES = expansion.c expansion_utils.c
EXP = $(addprefix $(EXPDIR)/, $(EXPFILES))

SRC = $(MAIN) $(TOKEN) $(ENV) $(B_IN) $(ARGV) $(AST) $(EXP)
OBJDIR = obj
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)

NAME = minishell

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -s -C libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo Minishell successfully compiled

clean:
	@$(MAKE) -s -C libft clean
	@$(RM) $(OBJDIR)

fclean: clean
	@$(MAKE) -s -C libft fclean
	@$(RM) $(NAME)
	@echo Successfully full cleaned

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
