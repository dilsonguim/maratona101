#include <stdio.h>


int main() {
  int n;
  scanf("%d", &n);

  for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) != 0) {
        printf("%d ", i + 1);
      }
    }
    printf("\n");
  }
}
