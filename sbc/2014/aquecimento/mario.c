/*
* Passo a passo do algoritmo:
*
* 1 - Ler os armários disponíveis
* 2 - Achar o intervalo com o maior número de armários livres
* 3 - Calcular a diferença entre o numero de armarios requisitado e o numero total de armários livres do intervalo
* 4 - exibir na tela
*/
#include <stdbool.h>
#include <stdio.h>

/*
* This function determines if a number is in an array
  * @param num: o numero procurado
  * @param arr: o array onde procurar
  */

bool isAt(int arr[], int size, int num) {
  for(int i = 0; i < size; i++) {
    if(arr[i] == num)
      return true;
  }

  return false;
}

/*
  * This function contais the logic of the program
  * @param arr: o array a ser analisado
  * @param size: o numero de elementos do array
  * @param request: o numero de armários pedidos
  */

int trocasArmario(int arr[], int size, int request) {
  
  if(request > size) {
    printf("Inválido\n");
    return -1;
  }

  int sizeMainArray = arr[size-1];
  int mainArray[sizeMainArray];

  for(int i = 0; i < sizeMainArray; i++) {
    mainArray[i] = i+1;
  }

  int maxInterv = 0;
  for(int i = 0; i <= sizeMainArray-request; i++) {
    int total = 0;
   
    for(int j = i; j < i+request; j++) {
      if(isAt(arr, size, mainArray[j])) {
        total++;
      }

      if(j == i+request-1 && total > maxInterv) {
          maxInterv = total;
      }
    }
  }

  return request - maxInterv;
}

/*
*void print_array(int arr[], int size) {
* for(int i = 0; i < size; i++) {
*  printf("%d ", arr[i]);
*}
*putchar('\n');
*}
*/  //  ---> Debug function
 
int main() {
  int num, request; //num é o número de armários livres e request é o número de armários requisitados
  scanf("%d %d", &request, &num);
  int array[num];

  for(int i = 0; i < num; i++) { //preenche the array
    scanf("%d", &array[i]);
  }

  int trocas = trocasArmario(array, num, request);
  printf("%d\n", trocas);

  //print_array(array, num); ---> Debug line
}
