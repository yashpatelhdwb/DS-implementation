#include <stdio.h>
#include <stdlib.h>

struct Node{
  int data;
  struct Node* next;
};
typedef struct Node* node;
node head,tail;
node createNewNode(){
  return (node)malloc(sizeof(node));
}
void enqueue2(int x){
  node current = createNewNode();
  current->data = x;
  current->next = head;
  head = current;
}

void enqueue(int x){
  if(head == NULL){
    enqueue2(x);
  }
  else{
    node temp1 = head;
    while(temp1->next != NULL){
      temp1 = temp1->next;
    }
    node temp2 = createNewNode();
    temp2->data = x;
    temp2->next = NULL;
    temp1->next = temp2;
  }
}

void print(){
  node temp = head;
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}
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
              enqueue(n);
              print();
              break;
      case 2: dequeue();
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
