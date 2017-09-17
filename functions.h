
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

int getSize(){
  node temp = head;
  int count=0;
  while(temp != NULL){
    temp = temp->next;
    count++;
  }
  return count;
}

void deleteAtBeginning(){
  node temp = head;
  temp  = temp->next;
  free(head);
  head = temp;
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
void deleteAtEnd(){
  node temp1 = head;
  // while(temp1->next != NULL){
  //   temp1 = temp1->next;
  // }
  for(int i=0; i<getSize()-2; i++) temp1 = temp1->next;
  node temp2 = temp1->next;
  temp1->next = NULL;
  free(temp2);
}

void print(){
  node temp = head;
  while(temp != NULL){
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}