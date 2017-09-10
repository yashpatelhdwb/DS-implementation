#include <stdio.h>
#include <stdlib.h>
#define size 10
int top = -1;
int _array[size];
void push(int v){
  _array[++top] = v;
}
void pop(){
  top--;
}
int peek(){
  return _array[top]; 
}
void isEmpty(){
  if(top <0) printf("stack is empty");
  else printf("stack has %d elements\n",top+1);
}
void print(){
  if(top <0) printf("stack is empty");
  else {
    printf("Elements: \n");
    for(int i=0; i<=top; i++){
      printf("%d ",_array[i]);
    }
    printf("\n");
  }
}
int main(){
  int ch;
  int n,p;
  printf("1.push\n2.pop\n3.peek\n4.isEmpty\n5.exit\n");
  while(1){
  scanf("%d",&ch);
  switch(ch){
    case 1: scanf("%d",&n);
            push(n);
            print();
            break;
    case 2: pop();
            print();
            break;
    case 3: p=peek();
            printf("peek function executed %d\n",p);
            break;
    case 4: isEmpty();
            break;
    case 5: exit(1);
    default: printf("I have no idea what you are trying to do!\n");
              exit(1);
  };
  // int _array[size];
  //int* top;
  //top = -1;

  }
  return 0;
}