#include <stdio.h>

int p[100];

void gerar(int i, int x, int n) {
  if (n == 0) {
    for (int j = 0; j < i; j++) {
      printf("%d ", p[j]);
    }
    printf("\n");
  }

  if (x <= n) {
    gerar(i, x + 1, n);

    p[i] = x;
    gerar(i + 1, x, n - x);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  gerar(0, 1, n);
}
