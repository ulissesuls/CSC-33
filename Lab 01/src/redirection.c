#include "redirection.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// Função para verificar e aplicar redirecionamento de entrada e saída
void handle_redirection(char **args) {
    for (int i = 0; args[i] != NULL; i++) {
        if (strcmp(args[i], ">") == 0) { // Redirecionamento de saída
            int fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd < 0) {
                perror("Erro ao abrir arquivo de saída");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDOUT_FILENO); // Substitui stdout pelo arquivo
            close(fd);
            args[i] = NULL; // Remove '>' e o nome do arquivo dos argumentos
        }
        else if (strcmp(args[i], "<") == 0) { // Redirecionamento de entrada
            int fd = open(args[i + 1], O_RDONLY);
            if (fd < 0) {
                perror("Erro ao abrir arquivo de entrada");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDIN_FILENO); // Substitui stdin pelo arquivo
            close(fd);
            args[i] = NULL; // Remove '<' e o nome do arquivo dos argumentos
        }
    }
}