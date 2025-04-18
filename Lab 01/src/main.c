#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "executor.h"

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Welcome to the miniature-shell.\n");

    while (1) {
        printf("cmd> ");
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            // Detecta fim de arquivo ou erro de leitura
            printf("\nExiting mini-shell.\n");
            break;
        }

        // Remove o caractere de nova linha do final da string
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0) continue; // Ignora entradas vazias

        // Divide o input em argumentos (tokens)
        char **args = parse_input(input);

        // Executa o comando com os argumentos
        execute_command(args);

        // Libera a memória alocada
        free(args);
    }

    return 0;
}
