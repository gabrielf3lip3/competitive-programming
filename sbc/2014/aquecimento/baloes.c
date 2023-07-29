#include <stdio.h>

int main() {
  int qtde;
  scanf("%d", &qtde);

  int pos[qtde];

  for(int i = 0; i < qtde; i++) {
    scanf("%d", &pos[i]);
  }

  int flechas = 0;
  for(int i = 0; i < qtde; i++) {
    if(i==0) flechas++;
    else if(pos[i] - pos[i-1] != -1) flechas++;

  }

  printf("%d\n", flechas);
}
