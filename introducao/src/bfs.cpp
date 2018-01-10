#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

void busca_em_largura(vector<vector<int> >& g,
                      vector<bool>& visitado,
                      int partida) {

  queue<int> fila;
  visitado[partida] = true;
  fila.push(partida);


  while (! fila.empty()) {
    int aqui = fila.front();
    fila.pop();
  
    printf("Retirei: %d\n", aqui + 1);

    for (int j = 0; j < g[aqui].size(); j++) {
      int vizinho = g[aqui][j];
      if (! visitado[vizinho]) {
        visitado[vizinho] = true;
        fila.push(vizinho);
      }
    }
  }

  
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  vector<vector<int> > g(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    printf("%d:", i + 1);
    for (int j = 0; j < g[i].size(); j++) {
      printf(" %d", g[i][j] + 1);
    }
    printf("\n");
  }

  printf("\n");

  vector<bool> visitado(n);

  for (int partida = 0; partida < n; partida++) {
    if (! visitado[partida]) {
      busca_em_largura(g, visitado, partida);
    }
  }

  printf("\nvisitados:");
  for (int i = 0; i < n; i++) {
    if (visitado[i]) {
      printf(" %d", i + 1);
    }
  }
  printf("\n");
}
