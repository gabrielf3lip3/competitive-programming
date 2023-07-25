#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int maxConsecInterval(int arr[], int size, int num_consec) {

    //int janela_soma = 0;
    //for (int i = 0; i < k; i++) {
    //    janela_soma += arr[i];
    //}

    //int max_soma = janela_soma;

    //for (int i = k; i < num_consec; i++) {
    //    janela_soma += arr[i] - arr[i - k];
    //    if (janela_soma > max_soma) {
    //        max_soma = janela_soma;
    //    }
    //}
  int min_trocas = INT_MAX;

  for(int i = 0; i <= size - num_consec; i++) {

    int interval[num_consec];
    for(int j = 0; j < num_consec; j++) {
      interval[j] = arr[i+j];
    }

    int trocas = 0;
    int index = 0;
    for(int j = 0; j < num_consec; j++) {
      if(arr[j] == interval[index]) {
        index++;
        if(index == size) {
          break;
        }
      } else {
        trocas++;
      }
    }

    if(trocas < min_trocas)
      min_trocas = trocas;
  }

  return min_trocas;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6};
    int tamanho_array = sizeof(array) / sizeof(array[0]);
    int qtde_armarios = 3;

    int resultado = maxConsecInterval(array, tamanho_array, qtde_armarios);
    printf("O número mínimo de trocas para o array é: %d\n", resultado);
    return 0;
}
