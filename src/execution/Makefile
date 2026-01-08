
NAME = a.out
CFLAGS = -Wall -Wextra -Werror -I../../headers -I../../libft
LIB = -Llibft -lft

RM = rm -rf

all:
	@cc $(CFLAGS) execution.c test.c apply_redir.c get_path.c error_msg_exit.c $(LIB) -o $(NAME)
	@echo test.c compiled with SRC files

clean:
	@$(RM) a.out
	@echo cleaned ONLY a.out
