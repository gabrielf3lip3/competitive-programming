#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dir {
  char direc;
  struct dir *next;
  struct dir *prev;
} DIR;

DIR* createDir(char v) {
  DIR* new = (DIR*)malloc(sizeof(DIR));
  new->direc = v;
  new->next = NULL;
  new->prev = NULL;
  return new;
}

void insertNode(DIR** head, DIR** tail, char v) {
  DIR* new = createDir(v);
  if(*head == NULL) {
    *head = new;
    *tail = new;
    new->next = *head;
    new->prev = *head;
  }
  else {
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    (*tail)->next = *head;
    (*head)->prev = *tail;
  }
} 

int main() {

  int num;
 
  DIR* head = NULL;
  DIR* tail = NULL;

  char directions[] = "NLSO";
  for(int i = 0; i < 4; i++) {
    insertNode(&head, &tail, directions[i]);
  }

  DIR* aux = head;

  scanf("%d", &num);
  char comm[num];
  scanf("%s", comm);

  for(int i = 0; i < num; i++) {
    if(comm[i] == 'E') {
      aux = aux->prev;  
    }
    else if(comm[i] == 'D') {
      aux = aux->next;
    }
  } 

  printf("n: %d commands: %c\n", num, aux->direc);
}
