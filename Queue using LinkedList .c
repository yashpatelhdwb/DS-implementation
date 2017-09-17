#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

node head,tail;

void dequeue(){
  node temp = head;
  if(temp == NULL) printf("Queue is empty\n");
  else{
    node temp1 = temp->next;
    free(temp);
    // temp1 = head;
    head = temp1;
  }
  print();
}
int getHead(){
  return head->data;
}
int getTail(){
  node tail = head;
  while(tail->next != NULL){
    tail = tail->next;
  }
  return tail->data;
}
int main(){
  head = tail = NULL;
  int ch,n;
  printf("1.enqueue\n2.dequeue\n3.Get head and rear\n4.exit\n");
  while(1){
    scanf("%d",&ch);
    switch(ch){
      case 1: scanf("%d",&n);
              insertAtEnd(n);
              print();
              break;
      case 2: deleteAtBeginning();
              print();
              break;
      case 3: printf("Head points to %d\n",getHead());
              printf("Tail points to %d\n",getTail());
              break;
      case 4: exit(1);
              break;
      default: printf("I have no idea what are you trying to do!\n");
    }
  }
  return 0;
}
