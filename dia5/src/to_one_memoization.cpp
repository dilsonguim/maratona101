#include <stdio.h>
#include <algorithm>

using namespace std;

#define TAM 100000

int tab[TAM];

int F(int n) {
  if (tab[n] != -1) return tab[n];

  if (n == 1) {
    tab[n] = 0;
    return 0;
  } else {
    int r = F(n - 1);
    if (n % 2 == 0) r = min(r, F(n / 2));
    if (n % 3 == 0) r = min(r, F(n / 3));

    r++;

    tab[n] = r;
   
    return r;
  }

}

int main() {
  for (int i = 0; i < TAM; i++) tab[i] = -1;

  int n;
  scanf("%d", &n);
  printf("%d\n", F(n));
}
