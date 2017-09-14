#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

typedef struct Node* node;
node head;
node createNewNode(){
  return (node)malloc(sizeof(node));
}
void insertAtBeginning(int x){
  node current = createNewNode();
  current->data = x;
  current->next = head;
  head = current;
}

void insertAtEnd(int x){
  if(head == NULL){
    insertAtBeginning(x);
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
void getTopOfStack(){
  node temp = head;
  if(temp == NULL) printf("Stack is empty\n");
  else{
    while(temp->next != NULL){
    temp =temp->next;
  }
  printf("right now TOP of the stack element is %d\n",temp->data);
  }
}

int getSize(){
  node temp = head;
  int c = 0;
  while(temp != NULL){
    temp = temp->next;
    c++;
  }
  return c;
}

void pop(){
  node temp1 = head;
  // int s = getSize();
  if(temp1 == NULL) printf("Stack is empty\n");
  else{
    for(int i=0; i<getSize()-2; i++){
      temp1 =temp1->next;
    }
    node temp2;
    temp2 = temp1->next;
    temp1->next = NULL;
    free(temp2);
    // getTopOfStack();
    print();
  }
}
void peek(){
  node temp = head;
  if(temp == NULL) printf("Stack is empty\n");
  else{
    while(temp->next != NULL){
      temp =temp->next;
    }
    printf("peek function executed\nHere's the value found:%d\n",temp->data);
  }
}
void isEmpty(){
  if(head == NULL){
    printf("Stack is empty");
  }
  else printf("Seems Like Stack isn't Empty\nThere are %d elements present in stack\n\n\n",getSize());
}
int main(){
  head = NULL;
  // int t,n,k,s;
  // printf("Number of queries? ");
  // scanf("%d",&t);
  // printf("");
  // while(t--){
  //   scanf("%d",&n);
  //   insertAtEnd(n);
  // }
  // print();
  // getTopOfStack();
  // printf("do you wanna perform pop operation? if yes press 1\n");
  // scanf("%d",&k);

  // if(k == 1){
  //   pop();
  // }
  printf("1.push\n2.pop\n3.peek\n4.isEmpty\n5.Get top of the stack\n6.exit\n");
    while(1){
      int ch,n;
      
      scanf("%d",&ch);
      switch(ch){
        case 1: scanf("%d",&n);
                insertAtEnd(n);
                print();
                break;
        case 2: pop();
                print();
                break;
        case 3: peek();
                break;
        case 4: isEmpty();
                break;
        case 5: getTopOfStack();
                break;
        case 6: exit(1);
                break;
        default: printf("I have no idea what you are trying to do!\n");
                exit(1);
      }  
    }

  return 0;
}
