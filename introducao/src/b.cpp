#include <stdio.h>

int main() {
  while (1) {
    int n;
    scanf("%d", &n);
    if (feof(stdin)) break;

    int ce[31];
    int cd[31];

    for (int i = 0; i < 31; i++) {
      ce[i] = 0;
      cd[i] = 0;
    }

    for (int i = 0; i < n; i++) {
      int tam;
      char lado;
      scanf("%d %c", &tam, &lado);

      if (lado == 'E') {
        ce[tam - 30]++;
      } else {
        cd[tam - 30]++;
      }
    }

    int pares = 0;
    for (int i = 0; i < 31; i++) {
      if (ce[i] < cd[i]) {
        pares += ce[i];
      } else {
        pares += cd[i];
      }
    }

    printf("%d\n", pares);
  }
}
