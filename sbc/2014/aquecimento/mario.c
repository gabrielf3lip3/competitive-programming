#include <stdio.h>

int main() {

  int n, l;
  scanf("%d %d", &l, &n);
  int dispo[n];

  for(int i = 0; i < n; i++) {
    scanf("%d", &dispo[i]);
  }

  printf("Array... ");
  for(int i = 0; i < n; i++) {
    printf("%d ", dispo[i]);
  }

  int intervs[l-n][2]; //guardar todos os intervalos
  
  for(int i = 0; i < l-n; i++) {
    
    for(int j = i; j < n; j++) {

      int maxSubInterv[2] = {0, 0}; //guarda o maior sub intervalo

      int inicio, fim, cons = 0; //guarda o inicio e o fim do intervalo
      printf("Is %d equal to %d?\n", dispo[j], dispo[j+1] - 1);
      if(dispo[j] == dispo[j+1] - 1) {
        printf("Consecutive founded at %d\n", j);
        if(cons == 0) {
          inicio = j-1;
          cons = 1;
        }

        fim = j;

      } else {
        int auxInterv[2] = {inicio, fim};
        if(auxInterv[1] - auxInterv[0] > maxSubInterv[1] - maxSubInterv[0]) {
          maxSubInterv[0] = auxInterv[0];
          maxSubInterv[1] = auxInterv[1];
        }
        cons = 0;
        inicio = 0;
        fim = 0;
      }
      intervs[j][0] = maxSubInterv[0];
      intervs[j][1] = maxSubInterv[1];
    }
  }

  for(int i = 0; i < l-n; i++) {
    printf("printing all the array...\n\n");
    printf("Start: %d end: %d\n", intervs[i][0], intervs[i][1]);
  }

  /*int saida = 1;
   *printf("%d\n", saida);
   *return 0;
  */
}
