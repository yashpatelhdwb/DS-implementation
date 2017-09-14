#include<stdio.h>
#include<stdlib.h>

struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};

typedef struct Node* node;
node head;

void insertAtHead(int value){
  node temp = (node)malloc(sizeof(node));
  temp->data = value;
  temp->next = head;
  temp->prev = NULL;
  head = temp;
}

void insertAtTail(int value){
  node temp1 = head;
  if(head == NULL){
    // printf("List is empty\n");
    insertAtHead(value);
    return;
  }
  
  while(temp1->next != NULL) temp1 = temp1->next;
  
  node temp2 = (node)malloc(sizeof(node));
  temp2->next = NULL;
  temp2->prev = temp1;
  temp2->data = value;
  temp1->next = temp2;
}

void deleteAtBeginning(){
  node temp = head;
  temp  = temp->next;
  temp->prev = NULL;
  free(head);
  head = temp;
}

void deleteAtEnd(){
  node temp1 = head;
  while(temp1->next != NULL){
    temp1 = temp1->next;
  }
  node temp2;
  temp2 = temp1->prev;
  temp2->next = NULL;
  free(temp1);
}

void print(){
  node temp = head;
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}
int getSize(){
  node temp = head;
  int count=0;
  while(temp != NULL){
    temp = temp->next;
    count++;
  }
  return count;
}
void printReverse(){
  node tempyou = head;
  while(tempyou->next != NULL) tempyou = tempyou->next;
  // for(int i=0; i<getSize(); i++){
    // temp = temp->next;
  // }
  node rear = tempyou;
  printf("Reverse print function is executing\n");
  while(rear != head){
    printf("%d ",rear->data);
    rear = rear->prev;
  }
  printf("\n");
}

int main(){
  int  t,n,c;
  printf("Enter the number of inputs\n");
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    insertAtTail(n);
  }
  print();
  printf("Do u wanna print this list in reverse order? if yes press 1 \n");
  scanf("%d",&c);
  if(c==1) printReverse();
  printf("Performing delete operation\n");
  deleteAtBeginning();
  print();
  printReverse();
  deleteAtEnd();
  print();
  return 0;
}