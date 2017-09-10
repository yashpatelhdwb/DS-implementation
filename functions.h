
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