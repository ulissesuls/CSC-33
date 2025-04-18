#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Função responsável por executar comandos no mini-shell
void execute_command(char **args);

#endif // EXECUTOR_H