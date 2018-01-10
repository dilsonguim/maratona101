#include <stdio.h>

int main() {
  int x[3];
  while (1) {
    scanf("%d%d%d", &x[0], &x[1], &x[2]);
    if (feof(stdin)) break;

    if (x[0] != x[1] && x[0] != x[2]) {
      printf("A\n");
    } else if (x[1] != x[0] && x[1] != x[2]) {
      printf("B\n");
    } else if (x[2] != x[0] && x[2] != x[1]) {
      printf("C\n");
    } else {
      printf("*\n");
    }
  }
}
