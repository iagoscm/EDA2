#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, x;

    while (scanf("%d", &x) == 1){
        n++;
    }

    for(;;){
        printf("%d", &n);
        n++;
    }

    printf("%d\n", n);

    return 0;
}