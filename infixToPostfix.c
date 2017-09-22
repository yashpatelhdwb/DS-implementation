#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stackFunctions.h" 


int isOperand(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
 
int prec(char ch){
    switch (ch){
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}
 
int infixToPostfix(char* exp){
    int i, k;
    struct Stack* stack = createStack(strlen(exp));
    if(!stack) 
        return -1 ;
    for (i = 0, k = -1; exp[i]; ++i){
        if (isOperand(exp[i])) exp[++k] = exp[i];   

        else if (exp[i] == '(') push(stack, exp[i]);
        
        else if (exp[i] == ')'){
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; 
            else
                pop(stack);
        }
        else {
            while (!isEmpty(stack) && prec(exp[i]) <= prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
 
    }   
    while (!isEmpty(stack)) exp[++k] = pop(stack);
 
    exp[++k] = '\0';
    printf( "%s", exp );
    printf("\n");
}
 

int main(){
    char exp[] = "a+b*(c/d-e)*(f-g/h)-i";
    // int t,n;
    // printf("Enter the number of inputs\n");
    // scanf("%d",&t);
    // printf("Enter the expression\n");
    // while(t--){
      // scanf("%s",exp);
      infixToPostfix(exp);      
    // }
    return 0;
}