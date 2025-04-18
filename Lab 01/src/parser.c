#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

#define MAX_ARGS 64  // Número máximo de argumentos

char **parse_input(char *input) {
    char **args = malloc(MAX_ARGS * sizeof(char *));
    if (!args) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    char *token = strtok(input, " "); // Divide a string por espaços
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i] = strdup(token); // Duplica o token para o vetor de argumentos
        if (!args[i]) {
            perror("strdup failed");
            exit(EXIT_FAILURE);
        }
        i++;
        token = strtok(NULL, " ");
    }

    args[i] = NULL; // execv requer que o último elemento seja NULL
    return args;
}

