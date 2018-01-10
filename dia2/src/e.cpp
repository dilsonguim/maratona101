#include <stdio.h>
#include <algorithm>

int main() {
  while (true) {
    int n, k;
    scanf("%d%d", &n, &k);
    if (feof(stdin)) break;

    int p[n];
    p[0] = 0;
    for (int i = 1; i < n; i++) {
      scanf("%d", &p[i]);
    }

    int d[n];
    for (int i = 1; i < n; i++) {
      d[i - 1] = p[i] - p[i - 1];
    }

    std::sort(d, d + n - 1);

    int r = p[n - 1];
    for (int i = 0; i < k - 1; i++) {
      r -= d[n - 2 - i];
    }
    
    printf("%d\n", r);
  }
}
