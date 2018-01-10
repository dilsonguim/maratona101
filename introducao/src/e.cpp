#include <stdlib.h>
#include <stdio.h>

#define INF 11234

int grid[112][112];
int d[112][112];
int a, b;

int fila_i[11234];
int fila_j[11234];
int entrada;
int saida;

void limpar_fila() {
  entrada = 0;
  saida = 0;
}

void colocar(int yi, int yj) {
  fila_i[entrada] = yi;
  fila_j[entrada] = yj;
  entrada++;
}

int retirar() {
  int x = saida;
  saida++;
  return x;
}

int tamanho() {
  return entrada - saida;
}

int movs[8][2] = {{1, 0},{-1, 0}, {0, 1}, {0, -1},{1, -1}, {1, 1}, {-1, -1},
{-1, 1}};


void busca_em_largura(int pi, int pj) {
  limpar_fila();

  d[pi][pj] = 0;
  grid[pi][pj] = 0;
  colocar(pi, pj);

  while (tamanho() > 0) {
    int aqui = retirar();
    int i = fila_i[aqui];
    int j = fila_j[aqui];

    for (int k = 0; k < 8; k++) {
      int novo_i = i + movs[k][0];
      int novo_j = j + movs[k][1];

      if (novo_i < 0) continue;
      if (novo_i >= a) continue;
      if (novo_j < 0) continue;
      if (novo_j >= b) continue;

      if (grid[novo_i][novo_j] != 1) continue;

      d[novo_i][novo_j] = d[i][j] + 1;
      grid[novo_i][novo_j] = 0;
      colocar(novo_i, novo_j);
    }
  }
}


int main() {
  int ntc;
  scanf("%d", &ntc);
  for (int tc = 0; tc < ntc; tc++) {
    scanf("%d%d", &a, &b);
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        scanf("%d", &grid[i][j]);
        d[i][j] = INF; 
      }
    }

    int pi, pj;
    scanf("%d%d", &pi, &pj);
    pi--;
    pj--;

    busca_em_largura(pi, pj);

    int resposta = 0;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        if (d[i][j] < INF) {
          if (d[i][j] > resposta) {
            resposta = d[i][j];
          }
        }
      }
    }

    
    printf("%d\n", resposta);

  }
}
