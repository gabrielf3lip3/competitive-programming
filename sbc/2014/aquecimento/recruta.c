#include <stdio.h> 

int main() {
  int numCommands;
  int actualDir = 0;
  char directions[] = "NLSO";
        
  scanf("%d", &numCommands);
        
  for (int i = 0; i < numCommands; i++){
    char comand;
    scanf(" %c", &comand);

    if (comand == 'E'){
      actualDir = (actualDir - 1 + 4) % 4;
    } else if (comand == 'D'){
      actualDir = (actualDir + 1) % 4;
    }
  }

  printf("%c\n", directions[actualDir]);
}
