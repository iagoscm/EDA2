#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    int count;
    struct node *next;
} Node;

int main() {
    int n;
    scanf("%d", &n);

    // Inicializa a lista vazia
    Node *head = NULL;

    // Lê os números de registro e atualiza a lista
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        // Procura na lista pelo número de registro
        Node *node = head;
        while (node != NULL && node->num != num) {
            node = node->next;
        }

        if (node == NULL) {
            // Se o número de registro não foi encontrado na lista, adiciona um novo elemento
            node = (Node *) malloc(sizeof(Node));
            node->num = num;
            node->count = 1;
            node->next = head;
            head = node;
        } else {
            // Se o número de registro já foi encontrado na lista, incrementa a contagem
            node->count++;
        }
    }

    // Conta quantos elementos da lista têm contagem maior do que zero
    int count = 0;
    Node *node = head;
    while (node != NULL) {
        if (node->count > 0) {
            count++;
        }
        node = node->next;
    }

    // Imprime o resultado
    printf("%d\n", count);

    // Libera a memória usada pela lista
    node = head;
    while (node != NULL) {
        Node *next = node->next;
        free(node);
        node = next;
    }

    return 0;
}
