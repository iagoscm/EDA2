#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXN 140000

typedef long long Item;

bool is_prohibited[MAXN];
Item prohibited[MAXN];

int cmpfunc (const void * a, const void * b) {
    return (*(Item*)a - *(Item*)b);
}

int binary_search(Item *v, int l, int r, int x){// [l, r[
    while(l + 1 < r){
        int mid = l + (r-l)/2;
        if(v[mid] <= x) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
    int n;
    scanf("%d", &n);

    // Leitura dos números proibidos
    for (int i = 0; i < n; i++) {
        scanf("%lli", &prohibited[i]);
    }

    // Ordena a lista de números proibidos
    qsort(prohibited, n, sizeof(Item), cmpfunc);

    // Leitura dos números a serem verificados
    Item x;
    while (scanf("%lli", &x) != EOF) {
        // Realiza a busca binária para verificar se o número está na lista de proibidos
        int ans = binary_search(prohibited, 0, n, x);

        if (prohibited[ans] == x) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }

    return 0;
}
