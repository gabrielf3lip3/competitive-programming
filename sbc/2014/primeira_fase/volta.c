#include <stdio.h>
#include <stdbool.h>

int get_turns(int time1, int time2) {

  int turns = 0;
  double pos1=0, pos2=0;
  double desloc1 = 1.0;
  double desloc2 = time1/(double)time2;

  while(true) {
    pos1+=desloc1;
    pos2+=desloc2;

    turns++;

    if(pos1 - pos2 >= 1) {
      break;
    }
  }

  return turns;
}

int main() {
  int time1, time2;
  scanf("%d %d", &time1, &time2);
  int turns = get_turns(time1, time2);
  printf("%d\n", turns);
}
