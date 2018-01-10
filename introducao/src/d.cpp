#include <bits/stdc++.h>

using namespace std;

void solitarios(int pb, int pe, string& s) {
  if (pb >= pe) return;

  printf("1");
  for (int i = pb; i < pe; i++) {
    if (s[i] == '1') printf("1");
    printf("%c", s[i]);
  }
  printf("1");
}

int main() {
  ios::sync_with_stdio(false);

  while (true) {
    string s;
    getline(cin, s);
    if (not cin) break;
    int n = s.size();

    int pb = 0;
    int pe = 0;
    int i = 0;
    while (i < n) {
      int j = i + 1;
      while (j < n and s[j] == s[i] and j - i < 9) j++;


      int t = j - i;
      if (t == 1) {
        pe++;
      } else {
        solitarios(pb, pe, s);

        while (t > 0) {
          int use = min(t, 9);
          printf("%d%c", use, s[i]);
          t -= use;
        }

        pb = j;
        pe = j;
      }
      
      i = j;
    }
    solitarios(pb, pe, s);
    printf("\n");

  }
}
