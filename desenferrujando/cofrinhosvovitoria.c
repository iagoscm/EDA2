#include <stdio.h>

int main() {
    int n, i, j, z, teste = 1;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        printf("Teste %d\n", teste++);
        int diff = 0;
        for (i = 0; i < n; i++) {
            scanf("%d %d", &j, &z);
            diff += j - z;
            printf("%d\n", diff);
        }
        printf("\n");
    }

    return 0;
}
