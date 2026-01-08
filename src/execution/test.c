

// ONLY FOR TESTING WITHOUT PARSING FUNC

#include "sub_minishell.h"
extern char **environ;
int	g_exit_code = -1;

void print_exit_code(int exit_code)
{
	ft_putstr_fd("Exit code: ", 2);
	ft_putnbr_fd(exit_code, 2);
	ft_putchar_fd('\n', 2);
}
void test_simple_cmd(void)
{
    t_ast cmd = {
        .type = CMD,
        .argv = (char *[]){"/bin/echo", "hello", NULL},
        .redir = NULL,
        .left = NULL,
        .right = NULL
    };
    g_exit_code = execute(&cmd, environ);
	print_exit_code(g_exit_code);
}
void test_redir_out(void)
{
    t_redir redir = {
        .type = REDIR_OUT,
        .file = "test_files/out.txt",
        .next = NULL
    };

    t_ast cmd = {
        .type = CMD,
        .argv = (char *[]){"/bin/echo", "hello", NULL},
        .redir = &redir,
        .left = NULL,
        .right = NULL
    };

    g_exit_code = execute(&cmd, environ);
	print_exit_code(g_exit_code);
}
void test_redir_in(void)
{
    t_redir redir = {
        .type = REDIR_IN,
        .file = "test_files/out.txt",
        .next = NULL
    };

    t_ast cmd = {
        .type = CMD,
        .argv = (char *[]){"/bin/cat", NULL},
        .redir = &redir,
        .left = NULL,
        .right = NULL
    };

    g_exit_code = execute(&cmd, environ);
	print_exit_code(g_exit_code);
}
void test_pipe(void)
{
    t_ast left = {
        .type = CMD,
        .argv = (char *[]){"/bin/echo", "-n", "hello", NULL},
        .redir = NULL
    };

    t_ast right = {
        .type = CMD,
        .argv = (char *[]){"/usr/bin/wc", "-c", NULL},
        .redir = NULL
    };

    t_ast pipe_node = {
        .type = PIPE,
        .left = &left,
        .right = &right
    };

    g_exit_code = execute(&pipe_node, environ);
	print_exit_code(g_exit_code);
}
void test_pipe_with_redir(void)
{
    t_ast left = {
        .type = CMD,
        .argv = (char *[]){"/bin/echo", "hello", NULL},
        .redir = NULL
    };

    t_redir redir = {
        .type = REDIR_OUT,
        .file = "test_files/count.txt",
        .next = NULL
    };

    t_ast right = {
        .type = CMD,
        .argv = (char *[]){"/usr/bin/wc", "-c", NULL},
        .redir = &redir
    };

    t_ast pipe_node = {
        .type = PIPE,
        .left = &left,
        .right = &right
    };

    g_exit_code = execute(&pipe_node, environ);
	print_exit_code(g_exit_code);
}
void test_heredoc(void)
{
    t_redir redir = {
        .type = HERE_DOC,
        .file = NULL,
        .next = NULL
    };

    t_ast cmd = {
        .type = CMD,
        .argv = (char *[]){"/bin/cat", NULL},
        .redir = &redir
    };

    g_exit_code = execute(&cmd, environ);
	print_exit_code(g_exit_code);
}
void test_append(void)
{
    t_redir redir = {
        .type = APPEND,
        .file = "test_files/append.txt",
        .next = NULL
    };

    t_ast cmd = {
        .type = CMD,
        .argv = (char *[]){"/bin/echo", "hello123", NULL},
        .redir = &redir,
        .left = NULL,
        .right = NULL
    };

    g_exit_code = execute(&cmd, environ);
	print_exit_code(g_exit_code);
}
void test_long_pipe_3(void)
{
    t_ast cmd1 = {
        .type = CMD,
        .argv = (char *[]){"/bin/echo", "-n", "hello", NULL},
        .redir = NULL
    };

    t_ast cmd2 = {
        .type = CMD,
        .argv = (char *[]){"/usr/bin/tr", "a-z", "A-Z", NULL},
        .redir = NULL
    };

    t_ast cmd3 = {
        .type = CMD,
        .argv = (char *[]){"/usr/bin/wc", "-c", NULL},
        .redir = NULL
    };

    t_ast pipe1 = {
        .type = PIPE,
        .left = &cmd1,
        .right = &cmd2
    };

    t_ast pipe2 = {
        .type = PIPE,
        .left = &pipe1,
        .right = &cmd3
    };

    execute(&pipe2, environ);
}
void test_long_pipe_4(void)
{
    t_ast cmd1 = {
        .type = CMD,
        .argv = (char *[]){"/usr/bin/printf", "a\nb\nc\n", NULL},
        .redir = NULL
    };

    t_ast cmd2 = {
        .type = CMD,
        .argv = (char *[]){"/bin/grep", "b", NULL},
        .redir = NULL
    };

    t_ast cmd3 = {
        .type = CMD,
        .argv = (char *[]){"/bin/cat", NULL},
        .redir = NULL
    };

    t_ast cmd4 = {
        .type = CMD,
        .argv = (char *[]){"/usr/bin/wc", "-l", NULL},
        .redir = NULL
    };

    t_ast p1 = { .type = PIPE, .left = &cmd1, .right = &cmd2 };
    t_ast p2 = { .type = PIPE, .left = &p1,   .right = &cmd3 };
    t_ast p3 = { .type = PIPE, .left = &p2,   .right = &cmd4 };

    execute(&p3, environ);
}
void test_long_pipe_5(void)
{
    t_ast cmd1 = {
        .type = CMD,
        .argv = (char *[]){"echo", "1 2 3 4", NULL},
        .redir = NULL
    };

    t_ast cmd2 = {
        .type = CMD,
        .argv = (char *[]){"/usr/bin/tr", " ", "\n", NULL},
        .redir = NULL
    };

    t_ast cmd3 = {
        .type = CMD,
        .argv = (char *[]){"wc", "-l", NULL},
        .redir = NULL
    };

    t_ast cmd4 = {
        .type = CMD,
        .argv = (char *[]){"tr", "-d", " ", NULL},
        .redir = NULL
    };

    t_ast cmd5 = {
        .type = CMD,
        .argv = (char *[]){"/bin/cat", NULL},
        .redir = NULL
    };

    t_ast p1 = { .type = PIPE, .left = &cmd1, .right = &cmd2 };
    t_ast p2 = { .type = PIPE, .left = &p1,   .right = &cmd3 };
    t_ast p3 = { .type = PIPE, .left = &p2,   .right = &cmd4 };
    t_ast p4 = { .type = PIPE, .left = &p3,   .right = &cmd5 };

    g_exit_code = execute(&p4, environ);
	print_exit_code(g_exit_code);
}
void test_cmd_not_found(void)
{
    t_ast cmd = {
        .type = CMD,
        .argv = (char *[]){"nosuchcommand", NULL},
        .redir = NULL
    };

    g_exit_code = execute(&cmd, environ);
	print_exit_code(g_exit_code);
}
void test_permission_denied(void)
{
    t_ast cmd = {
        .type = CMD,
        .argv = (char *[]){"./test_files/noexec.sh", NULL},
        .redir = NULL
    };

    g_exit_code = execute(&cmd, environ);
	print_exit_code(g_exit_code);
}
void test_redir_in_fail(void)
{
    t_redir redir = {
        .type = REDIR_IN,
        .file = "test_files/nofile.txt",
        .next = NULL
    };

    t_ast cmd = {
        .type = CMD,
        .argv = (char *[]){"cat", NULL},
        .redir = &redir
    };

    g_exit_code = execute(&cmd, environ);
	print_exit_code(g_exit_code);
}
void test_pipe_right_cmd_not_found(void)
{
    t_ast left = {
        .type = CMD,
        .argv = (char *[]){"/bin/echo", "hello", NULL},
        .redir = NULL
    };

    t_ast right = {
        .type = CMD,
        .argv = (char *[]){"nosuchcommand", NULL},
        .redir = NULL
    };

    t_ast pipe_node = {
        .type = PIPE,
        .left = &left,
        .right = &right
    };

    g_exit_code = execute(&pipe_node, environ);
	print_exit_code(g_exit_code);
}
void test_pipe_left_cmd_not_found(void)
{
    t_ast left = {
        .type = CMD,
        .argv = (char *[]){"nosuchcommand", NULL},
        .redir = NULL
    };

    t_ast right = {
        .type = CMD,
        .argv = (char *[]){"wc", "-c", NULL},
        .redir = NULL
    };

    t_ast pipe_node = {
        .type = PIPE,
        .left = &left,
        .right = &right
    };

    g_exit_code = execute(&pipe_node, environ);
	print_exit_code(g_exit_code);
}
void test_redir_out_fail(void)
{
    t_redir redir = {
        .type = REDIR_OUT,
        .file = "/root/test.txt",
        .next = NULL
    };

    t_ast cmd = {
        .type = CMD,
        .argv = (char *[]){"echo", "hello", NULL},
        .redir = &redir
    };

    g_exit_code = execute(&cmd, environ);
	print_exit_code(g_exit_code);
}
void test_long_pipe_middle_fail(void)
{
    t_ast cmd1 = {
        .type = CMD,
        .argv = (char *[]){"echo", "hello", NULL},
        .redir = NULL
    };

    t_ast cmd2 = {
        .type = CMD,
        .argv = (char *[]){"nosuch", NULL},
        .redir = NULL
    };

    t_ast cmd3 = {
        .type = CMD,
        .argv = (char *[]){"wc", "-c", NULL},
        .redir = NULL
    };

    t_ast p1 = { .type = PIPE, .left = &cmd1, .right = &cmd2 };
    t_ast p2 = { .type = PIPE, .left = &p1,   .right = &cmd3 };

    g_exit_code = execute(&p2, environ);
	print_exit_code(g_exit_code);
}


int	main(void)
{
    test_simple_cmd();
    test_redir_out();
    test_redir_in();
    test_pipe();
    test_pipe_with_redir();

    test_append();
    test_append();
    //test_heredoc(); // -w-

    test_long_pipe_3(); // 5
    test_long_pipe_4(); // 1
    test_long_pipe_5(); // 4



	// error handling
	// nosuchcommand
	test_cmd_not_found();

	/*	
		echo hello > noexec.sh
		chmod 644 noexec.sh
	*/
	test_permission_denied(); // this test case is hard to fix :')

	// cat < nofile.txt
    test_redir_in_fail(); 
	// shld print "bash: nofile.txt: No such file or directory" 
	// exit code = 1

	// echo hello | nosuchcommand
	test_pipe_right_cmd_not_found();
	// "nosuchcommand: command not found"
	
	// nosuchcommand | wc -c
	test_pipe_left_cmd_not_found();

	// echo hello > /root/test.txt
	test_redir_out_fail();

	// echo hello | nosuch | wc -c
	test_long_pipe_middle_fail();

	// echo hello | nosuch | wc -c
	test_long_pipe_middle_fail();

    return 0;
}
