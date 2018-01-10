#include <stdio.h>

#define MAX_X 11234
#define INF 11234

int c[MAX_X];
int resta[MAX_X];
int N, M;
int L;
int k;

int resolve() {
  if ((N * 100) % L != 0) {
    return INF;
  }

  int col = (N * 100) / L;

  for (int i = 0; i < MAX_X; i++) {
    resta[i] = c[i];
  }

  int cont = 0;
  for (int tam = MAX_X - 1; tam > 0; tam--) {
    if (tam > M) continue;
    while (resta[tam] > 0) {
      if (col == 0) break;
      if (tam == M) {
        resta[tam]--;
        cont++;
        col--;
      } else {
        int par = M - tam;
        if ((par != tam && resta[par] > 0) || (par == tam && resta[par] > 1)) {
          resta[tam]--;
          resta[par]--;
          cont += 2;
          col--;
        } else {
          break;
        }
      }
    }
  }

  if (col > 0) return INF;

  return cont;
}

int main() {
  while (true) {
    scanf("%d%d", &N, &M);
    if (N == 0 && M == 0) break;

    scanf("%d", &L);
    scanf("%d", &k);

    for (int i = 0; i < MAX_X; i++) c[i] = 0;

    for (int i = 0; i < k; i++) {
      int xi;
      scanf("%d", &xi);
      c[xi]++;
    }

    int r1 = resolve();
    int tmp = N;
    N = M;
    M = tmp;
    int r2 = resolve();

    int resposta = r1;
    if (r2 < r1) resposta = r2;

    if (resposta == INF) {
      printf("impossivel\n");
    } else {
      printf("%d\n", resposta);
    }
  }
}
