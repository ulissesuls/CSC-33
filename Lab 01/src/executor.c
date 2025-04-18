#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "executor.h"
#include "redirection.h"  // Incluir a função de redirecionamento

void execute_command(char **args) {
    if (args[0] == NULL) {
        return; // Nenhum comando a ser executado
    }

    pid_t pid = fork(); // Cria processo filho

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Processo filho
        handle_redirection(args); // Aplica redirecionamentos se existirem
        execv(args[0], args);     // Executa o comando
        perror("execv failed");  // Se execv falhar
        exit(EXIT_FAILURE);
    } else { // Processo pai
        int status;
        waitpid(pid, &status, 0); // Espera o processo filho terminar
    }
}
