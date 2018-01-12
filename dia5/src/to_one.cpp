#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  int F[n + 1];

  F[1] = 0;
  for (int i = 2; i <= n; i++) {
    F[i] = F[i - 1];

    if (i % 2 == 0) {
      F[i] = min(F[i], F[i / 2]);
    }

    if (i % 3 == 0) {
      F[i] = min(F[i], F[i / 3]);
    }

    F[i]++;
  }

  printf("%d\n", F[n]);
}
