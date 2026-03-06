# minishell
A simplified version of a shell referenced from bash, focusing on process creation, command execution, and parsing.
Group project (2-person team)

## Compilation
Compile the project using:
```
make
```
Other commands:
```
make clean
make fclean
make re
```

---

## Usage
Run the shell:
```
./minishell
```

## Features
Minishell supports the following features:

### Command Execution
- Execute programs using the system PATH
- Handle absolute and relative paths
- Support for multiple commands

### Pipes
- Pipe output from one command to another using `|`
- Example:
```
ls -l | grep minishell
```

### Redirections
- Input redirection `<`
- Output redirection `>`
- Append redirection `>>`
- Heredoc `<<`
Example:
```
echo hello > file.txt
cat < file.txt
```

### Environment Variables
- Expand environment variables using `$`
- Example:
```
echo $HOME
```

### Built-in Commands
- `echo`
- `cd`
- `pwd`
- `export`
- `unset`
- `env`
- `exit`

### Signals
- Handles `Ctrl+C`
- Handles `Ctrl+D`
- Handles `Ctrl+\`

Behavior should mimic bash where possible.

## Authors
- sel-L
- Shou Xiang
