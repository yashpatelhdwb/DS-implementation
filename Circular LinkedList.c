#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
node head;

void changeNULLToHead(){
  node temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = head;
}


int main(){
  head = NULL;
  int t,n;
  printf("Input the number of inputs?\n");
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    insertAtEnd(n);
  }
  changeNULLToHead();
  print();

  return 0;
}