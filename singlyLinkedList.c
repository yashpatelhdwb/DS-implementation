#include <stdio.h>
#include <stdlib.h>
struct node{
  int data;
  struct node* next;
};
typedef struct node* NODE;
NODE head;
void insertAtBeginning(int x){
  NODE new = (NODE)malloc(sizeof(NODE));
  new->data = x;
  new->next = head;
  head = new;
}

void insertAtEnd(int x){
  NODE temp = head;
  if(temp == NULL){ 
    // printf("List is empty\n");
    insertAtBeginning(x);
  }
  else{
    while(temp->next != NULL) temp = temp->next;
    NODE new = (NODE)malloc(sizeof(NODE));
    new->data = x;
    new->next = NULL;
    temp->next = new;
  }
}

void print(){
  NODE temp = head;
  if(head == NULL) printf("List is empty");
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}


void searchX(int x){
  NODE temp = head;
  int e=0;
  while(temp != NULL){
    if(temp->data ==x) {
      printf("%d is present in this list\n",x);
      e=1;
      break;
    }
    temp = temp->next;
  }
  if(e!=1) printf("%d is not present in this list\n",e);
}
int main(){
  head = NULL;
  // print();
  insertAtEnd(1);
  insertAtEnd(2);
  insertAtEnd(3);
  insertAtEnd(4);
  print();
  
    searchX(1);
  return 0;
}