#include <stdio.h>

int main(){

    int n, x, soma;
    soma = 0;

    scanf("%d", &n);

    if(n >= 0 && n <= 50){
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            soma += x;
        }
    }

    printf("%d\n", soma);

    return 0;
}