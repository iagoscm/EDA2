#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, cod, nota, dia = 1;

    while (scanf("%d", &n) == 1) {
        int maior_nota = -1, menor_cod = 1e9, cod_maior_nota = 1e9;

        for (int i = 0; i < n; i++) {
            scanf("%d%d", &cod, &nota);

            if (nota > maior_nota || (nota == maior_nota && cod < menor_cod)) {
                maior_nota = nota;
                menor_cod = cod;
            }
        }

        printf("Dia %d\n%d\n\n", dia, menor_cod);
        dia++;
    }

    return 0;
}
