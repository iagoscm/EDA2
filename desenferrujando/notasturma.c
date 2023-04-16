#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  char matricula[10];
  double mediaAtividades;
  double mediaProvas;
  struct celula *prox;
} celula;

void relatorioMediaAtividades(celula *le, celula *l1, celula *l2, double media) {
  celula *p = le->prox, *p1 = l1, *p2 = l2;

  while (p != NULL) {
    if (p->mediaAtividades <= media) {
      p1->prox = p;
      p1 = p1->prox;
    } else {
      p2->prox = p;
      p2 = p2->prox;
    }
    p = p->prox;
  }

  p1->prox = NULL;
  p2->prox = NULL;
}
