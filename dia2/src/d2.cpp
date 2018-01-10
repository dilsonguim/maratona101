#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX_X 11234
#define INF 11234

int c[MAX_X];
int N, M;
int L;
int k;

int resolve() {
  if ((N * 100) % L != 0) {
    return INF;
  }

  int col = (N * 100) / L;

  int cont = 0;
  for (int tam = M; tam > 0 && col > 0; tam--) {
    if (tam == M) {
      int usar = min(c[tam], col);
      col -= usar;
      cont += usar;
    } else {
      int par = M - tam;
      if (par > tam) break;
      int fazer;
      if (par == tam) {
        fazer = c[tam] / 2;
      } else {
        fazer = min(c[tam], c[par]);
      }
      fazer = min(fazer, col);
      col -= fazer;
      cont += 2 * fazer;
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

    memset(c, 0, sizeof(c));

    for (int i = 0; i < k; i++) {
      int xi;
      scanf("%d", &xi);
      c[xi]++;
    }

    int r1 = resolve();
    swap(N, M);
    int r2 = resolve();

    int resposta = min(r1, r2);
    
    if (resposta == INF) {
      printf("impossivel\n");
    } else {
      printf("%d\n", resposta);
    }
  }
}
