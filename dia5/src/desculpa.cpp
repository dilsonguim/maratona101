#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int teste = 0;
  while (1) {
    teste++;
    int n, c;
    scanf("%d%d", &c, &n);
    if (c == 0 and n == 0) break;

    int p[n];
    int f[n];
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &p[i], &f[i]);
    }

    int F[n + 1][c + 1];

    for (int k = 0; k <= c; k++) F[0][k] = 0;
   
    for (int q = 1; q <= n; q++) {
      for (int k = 0; k <= c; k++) {
        F[q][k] = F[q - 1][k];

        if (k >= p[q - 1]) {
          int novo_k = k - p[q - 1];
          int felicidade = f[q - 1] + F[q - 1][novo_k];
          F[q][k] = max(F[q][k], felicidade);
        }
      }
    }

    printf("Teste %d\n%d\n\n", teste, F[n][c]);
  }
}
