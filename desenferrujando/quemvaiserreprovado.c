#include <stdio.h>
#include <string.h>

typedef struct p {
    int points;
    char name[21];
} p;

int menor(p a, p b) {
    if (a.points != b.points) {
        return a.points < b.points;
    } else {
        return strcmp(a.name, b.name) > 0;
    }
}

int main() {
    int n;
    int t = 1;

    while (scanf("%d", &n) != EOF) {
        p alunos[101];
        int lowest_index = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%s %d", alunos[i].name, &alunos[i].points);
            if (menor(alunos[i], alunos[lowest_index]))
                lowest_index = i;
        }

        printf("Instancia %d\n%s\n\n", t++, alunos[lowest_index].name);
    }

    return 0;
}
