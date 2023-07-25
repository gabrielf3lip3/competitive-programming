#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int maxSumJanelaDeslizante(int arr[], int n, int k) {

  if(n < k) {
    printf("Tamanho da janela maior que o tamanho do array.\n");
    return -1;
  }

  int janela_soma = 0;
  for (int i = 0; i < k; i++) {
    janela_soma += arr[i];
  }

  int max_soma = janela_soma;

  for (int i = k; i < n; i++) {
    janela_soma += arr[i] - arr[i - k];
    if (janela_soma > max_soma) {
      max_soma = janela_soma;
    }
  }

  return max_soma;
}

int main() {
    int array[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int tamanho_array = sizeof(array) / sizeof(array[0]);
    int tamanho_janela = 3;

    int resultado = maxSumJanelaDeslizante(array, tamanho_array, tamanho_janela);
    printf("A soma máxima da janela de tamanho %d é: %d\n", tamanho_janela, resultado);
    return 0;
}
