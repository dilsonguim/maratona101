#include <stdio.h>

int usado[20];
int p[20];
int n;

void gerar(int i) {
  
  if (i == n) {
     for (int j = 0; j < n; j++) {
      printf("%d ", p[j] + 1);
     }
     printf("\n");
     return;
  }

  for (int proximo = 0; proximo < n; proximo++) {
    if (usado[proximo]) continue;

    usado[proximo] = 1;
    p[i] = proximo;
    gerar(i + 1);
    usado[proximo] = 0;
  }
}

int main() {
  scanf("%d", &n);
  gerar(0);
}
