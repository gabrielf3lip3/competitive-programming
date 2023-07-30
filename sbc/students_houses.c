#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct coordinates {
  int x;
  int y;
} coordi;

double distance(int x1, int y1, int x2, int y2) {
   return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

double distanceToOrigin(int x, int y) {
  return distance(x, y, 0, 0);
}

void sort(coordi houses[], int size) {
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size-1; j++) {
      if(distanceToOrigin(houses[j].x, houses[j].y) > distanceToOrigin(houses[j+1].x, houses[j+1].y)) {
        coordi temp = houses[j];
        houses[j] = houses[j+1];
        houses[j+1] = temp;
      }
    }
  }
}

double getCost(coordi houses[], int size) {
  double sum = 0;
  for(int i = 0; i < size-1; i+=2) {
    sum+=distance(houses[i].x, houses[i].y, houses[i+1].x, houses[i+1].y);
  }

  return sum;
}

int main() {

  int num;
  scanf("%d", &num);

  num*=2;
  coordi houses[num];
  for(int i = 0; i < num; i++) {
    coordi new;
    scanf("%d %d", &new.x, &new.y);
    houses[i] = new;
  }

  sort(houses, num);

  for(int i = 0; i < num; i++) {
    printf("%d %d\n", houses[i].x, houses[i].y);
  }

  printf("%.2lf\n", getCost(houses, num));
}
