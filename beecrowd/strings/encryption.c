#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* strrev(char *str) {
  char *p1, *p2;
  if(!str || !*str)
    return str;
  for(p1 = str, p2 = str+strlen(str)-1; p2>p1; ++p1, --p2) {
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
  }
  return str;
}

void encrypt(char** strings, int num) {
  for(int i = 0; i < num; i++) {
    for(int j = 0; j < strlen(strings[i]); j++) {
      if(isalpha(strings[i][j])) {
        strings[i][j] = strings[i][j]+3;
      }
    }

    strrev(strings[i]);
    for(int k = strlen(strings[i])/2; k < strlen(strings[i]); k++) {
      strings[i][k] = strings[i][k]-1;
    }
  }
}

int main() {
  int num;
  scanf("%d", &num);

  char** strings = (char**)malloc(sizeof(char*)*num);

  for (int i = 0; i < num; i++) {
    strings[i] = (char*)malloc(sizeof(char)*20);
  }

  for(int i = 0; i < num; i++) {
    char* buff = (char*)malloc(sizeof(char)*20);
    size_t n = 20;
    getline(&buff, &n,  stdin);
    strcpy(strings[i], buff);
    free(buff);
  }

  encrypt(strings, num);

  for (int i = 0; i < num; i++) {
    printf("%s\n", strings[i]);
  }

  for (int i = 0; i < num; i++) {
    free(strings[i]);
  }

  free(strings);
}
