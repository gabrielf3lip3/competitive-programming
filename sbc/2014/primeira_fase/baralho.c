#include <stdio.h>
#include <stdbool.h>

void embaralha(int cards[], int size) {
  int aux[size];
  int start = 0;
  int middle = size/2;

  for(int i = 0; i < size; i++) {
    if(i%2==0) {
      aux[i] = cards[middle];
      middle++;
    }
    else {
      aux[i] = cards[start];
      start++;
    }
  }

  for (int i = 0; i < size; i++) {
    cards[i] = aux[i];
  }
}

bool isEqual(int arr1[], int arr2[], int size) {
  for(int i = 0; i < size; i++) {
    if(arr1[i] != arr2[i]) return false;
  }
  return true;
}

int get_qtde(int num) {
  int aux[num];
  int cards[num];

  for(int i = 0; i < num; i++) {
    aux[i] = i+1;
    cards[i] = i+1;
  }

  int turns = 0;

  while(true) {
    embaralha(aux, num);
    turns++;

    if(isEqual(aux, cards, num))
      break;
  }

  return turns;
}

int main() {

  unsigned int num;
  scanf("%d", &num);

  int qtde = get_qtde(num);
  printf("%d\n", qtde);
}
