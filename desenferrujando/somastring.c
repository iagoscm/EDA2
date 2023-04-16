#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, sum;
    char s[101];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%s", s);

        sum = 0;
        for (j = 0; j < strlen(s); j++) {
            if (s[j] >= '0' && s[j] <= '9') {
                sum += s[j] - '0';
            }
        }

        printf("%d\n", sum);
    }

    return 0;
}
