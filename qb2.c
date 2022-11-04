//Conversion of infix to Postfix expression

#include<stdio.h>
#include<string.h>
#define MAX 100

char infix[MAX];
char postfix[MAX];
char stack[MAX];
int top=-1;

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char sym){
    if(top==MAX-1)
        printf("Stack Overflow");

    top++;
    stack[top]=sym;
}

char pop(){
    char sym;
    if(top==-1)
        printf("Empty\n");

    sym=stack[top];
    top--;

    return sym;
}

int precedence(char sym){
    switch (sym)
    {
    case '^':
        return 3;
        break;

    case '/':
    case '*':
        return 2;
        break;

    case '+':
    case '-':
        return 1;
        break;
    
    default:
        return 0;
        break;
    }
}

void inTopost(){
    char symbol;
    char next;
    int j=0;

    for(int i=0;i<strlen(infix);i++){
        symbol=infix[i];

        switch (symbol)
        {
        case '(':
            push(symbol);            
            break;
        
        case ')':
            while((next=pop())!='(')
                postfix[j++]=next;
                break;
        
        case '+':

        case '-':

        case '*':

        case '/':

        case '^':

            while(!isEmpty() && precedence(stack[top])>=precedence(symbol)){
                postfix[j++]=pop();
            }
            push(symbol);
            break;      
        
        default:
            postfix[j++]=symbol;
            break;
        }
    }

    while(!isEmpty()){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

void display(){
    int i=0;
    printf("The postfix expression is:\n");
    while(postfix[i]){
        printf("%c",postfix[i++]);
    }
}

void main(){

    printf("Enter infix expression:\n");
    gets(infix);

    inTopost();
    display();

}