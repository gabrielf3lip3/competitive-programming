#include <stdio.h>

int get_players(int lines, int columns, int games[lines][columns]) {
  int ret = 0;

  for(int i = 0; i < lines; i++) {
    int aux = 1;
    for(int j = 0; j < columns; j++) {
      aux*=games[i][j];
    }
    if(aux != 0) ret++;
  }

  return ret;
}

int main() {

  int lines, columns;
  scanf("%d %d", &lines, &columns);

  int games[lines][columns];

  for(int i = 0; i < lines; i++) {
    for(int j = 0; j < columns; j++) {
      scanf("%d", &games[i][j]);
    }
  }

  int qtde = get_players(lines, columns, games);
  printf("%d\n", qtde);
  return 0;
}
