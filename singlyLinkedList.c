#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
node head;

int main(){
  head = NULL;
  int n,t;
  printf("Number of inputs?\n");
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    insertAtEnd(n);
  }
  printf("List contains: ");
  print();
  deleteAtBeginning();
  print();
  deleteAtEnd();
  print();
  return 0;
}