#include <stdio.h>
#define int long long

void imprime_lista(int *vet, int pos, int soma, const int max, const int tam){
    if(pos == tam)
        return;

    if(soma + vet[pos] > max){
        imprime_lista(vet, pos+1, 0, max, tam);
        printf("%lli\n", vet[pos]);
    }
    else
        imprime_lista(vet, pos+1, soma + vet[pos], max, tam);
}

int main(){
    int x, max_soma;
    int lista[(int)1e5+66];
    int tamanho_lista = 0;
    while(scanf("%lli", &x) != EOF){
        if(x == 0) break;
        lista[tamanho_lista++] = x;
    }

    scanf("%lli", &max_soma);
    imprime_lista(lista, 0, 0, max_soma, tamanho_lista);
    return 0;
}
