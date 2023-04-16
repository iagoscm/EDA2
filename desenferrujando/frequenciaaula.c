#include <stdio.h>
#include <stdbool.h>

#define MAX_N 1000001 // limite superior para N
#define MAX_ID 1000001 // limite superior para o número de registro

bool present[MAX_ID]; // vetor para armazenar se um aluno está presente ou não

int main() {
    int n, id;
    scanf("%d", &n);

    // inicializa todos os alunos como ausentes
    for (int i = 0; i < MAX_ID; i++) {
        present[i] = false;
    }

    // verifica se o aluno está presente na aula
    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        present[id] = true;
    }

    // conta quantos alunos estão presentes na aula
    int count = 0;
    for (int i = 0; i < MAX_ID; i++) {
        if (present[i]) {
            count++;
        }
    }

    // imprime o resultado
    printf("%d\n", count);

    return 0;
}
