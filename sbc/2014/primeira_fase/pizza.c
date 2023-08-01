#include <stdio.h>

char isPossible(int positions[], int circu, int size) {
  if(circu < size) return 'N';

  for(int i = 1; i < size; i++) {
    if(positions[i] - positions[i-1] < size) return 'N';
  }
  return 'S';
}

int main() {

  int circu, num;
  scanf("%d %d", &circu, &num);

  int positions[num];
  for(int i = 0; i < num; i++) {
    scanf("%d", &positions[i]);
  }

  char result = isPossible(positions, circu, num);
  printf("%c\n", result);
}
