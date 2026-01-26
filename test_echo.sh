#!/bin/bash
./minishell << 'INNER'
echo hello - world
echo "-" test
echo - test
exit
INNER
