#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

int main() {
    char *text[MAX_SIZE]; // array de ponteiros para char
    int size = 0; // tamanho atual do array
    int cursor = -1; // cursor para navegar pelo array
    char input[MAX_SIZE + 8]; // +8 para acomodar "inserir " ou "desfazer\n"

    while (fgets(input, sizeof(input), stdin)) {
        if (input[0] == 'i') { // comando inserir
            text[++cursor] = (char *) malloc(sizeof(char) * MAX_SIZE); // aloca memória para a string inserida
            sscanf(input, "inserir %[^\n]", text[cursor]); // lê a string inserida
            size = cursor + 1; // atualiza o tamanho do array
        } else if (input[0] == 'd') { // comando desfazer
            if (cursor >= 0) { // se houver algo para desfazer
                printf("%s\n", text[cursor--]); // imprime a última string inserida e decrementa o cursor
            } else {
                printf("NULL\n"); // se não houver nada para desfazer, imprime NULL
            }
        }
    }

    // libera a memória alocada para as strings
    for (int i = 0; i < size; i++) {
        free(text[i]);
    }

    return 0;
}
