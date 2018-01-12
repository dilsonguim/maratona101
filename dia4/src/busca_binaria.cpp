#include <stdio.h>

int a[9] = {3, 6, 10, 21, 33, 42, 42, 44, 50};
int n = 9;

int main() {
  int x;
  scanf("%d", &x);

  int inicio = 0;
  int fim = n;

  while (inicio < fim) {
    int meio = (inicio + fim) / 2;

    if (a[meio] < x) {
      inicio = meio + 1;
    } else if (a[meio] > x) {
      fim = meio;
    } else {
      printf("%d\n", meio);
      break;
    }
  }

}
