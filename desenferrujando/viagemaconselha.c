#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, cod, nota, codtemp, notatemp, dia = 1, i = 0;

    for( ; ; ){
        scanf("%d", &n);
        printf("%d\n", n);
        if(n > 200 || n < 1)
            break;
        printf("%d\n", n);
        cod = 0;
        nota = 0;
        for( ; ; ){
            printf("i = %d\n", i);
            scanf("%d %d", &codtemp, &notatemp);
            if(notatemp > nota){
                cod = codtemp;
                nota = notatemp;
            }
            printf("%d", i);
        }
        printf("Dia %d", dia);
        dia++;
    }

    return 0;

}