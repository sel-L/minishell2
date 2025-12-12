# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 10:47:03 by wshou-xi          #+#    #+#              #
#    Updated: 2025/12/13 00:19:14 by wshou-xi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Iheaders -I./libft/
LIB = -lreadline -lhistory -Llibft
RM = rm -rf
VALGRIND = valgrind --suppressions=readline.supp --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes --verbose

MAINDIR = src/parsing
MAINFILES = main.c
MAIN = $(addprefix $(MAINDIR)/, $(MAINFILES))

SRC = $(MAIN)
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
