#include <stdio.h>

int n;
int tem[20];

void gerar(int i) {
  if (i == n) {
    for (int i = 0; i < n; i++) {
      if (tem[i]) printf("%d ", i + 1);
    }
    printf("\n");
    
    return;
  }

  tem[i] = 0;
  gerar(i + 1);

  tem[i] = 1;
  gerar(i + 1);
}

int main() {
  scanf("%d", &n);

  gerar(0);
}
