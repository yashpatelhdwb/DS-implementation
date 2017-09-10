#include <stdio.h>
#include <stdlib.h>
#define size 10
int _array[size];
int head=-1,rear=-1;

void insert(int value){
  if(head == -1 && rear == -1){
    head++; rear++;
    _array[head] = value;
  }
  else if(rear >= size-1) printf("queue is full\n");

  else _array[++rear] = value;
}

void delete(){
  if(rear == -1) printf("queue is empty\n");
  else rear--;
}

int getHead(){
  return head;
}

int getRear(){
  return rear;
}
void print(){
  for(int i=0; i<=rear; i++){
    printf("%d ", _array[i]);
  }
  printf("\n");
}


int main(){
  int t;
  printf("How many number of inputs?\nMAX SIZE is 10\n");
  scanf("%d",&t);
  if(t<0 || t>10) t = 10;
  while(t--){
    insert(t);
  }
  //delete();
  print();
  insert(size);
  print();

}