//Program to convert an infix expression to an postfix expression....

#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX 100

char stack[MAX];
char infix[MAX];
char postfix[MAX];
int top=-1;

int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(char sys){
    if(top==MAX-1){
        printf("Stack Overflow");
    }
    top++;
    stack[top]=sys;    
}

char pop(){
    char val;
    if(top==-1){
        printf("Stack Underflow\n");
    }
    val=stack[top];
    top--;
    return val;
}

int precedence(char sys){
    switch (sys)
    {
    case '^':
        return 3;
        break;

    case '/':
    case '*':
        return 2;

    case '+':
    case '-':
        return 1;
    
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
    printf("The equivalent postfix expression is:\n");
    while(postfix[i]){
        printf("%c",postfix[i++]);  
    }
}

int eval_post(){
    for(int i=0;i<strlen(postfix);i++){
        if(postfix[i]>='0' && postfix[i]<='9'){
            push(postfix[i]-'0');
        }
        else{
            int a=pop();
            int b=pop();
            switch (postfix[i])
            {
            case '^':
                push (pow(b,a));
                break;

            case '*':
                push(b*a);
                break;
            
            case '/':
                push(b/a);
                break;

            case '+':
                push(b+a);
                break;

            case '-':
                push(b-a);
                break;

            default:
                break;
            }
        }
    }
    return pop();
}

int main(){
    int result;
    printf("Enter the infix expression:\n");
    gets(infix);

    inTopost();
    display();
    result=eval_post();
    printf("\nThe result is %d ",result);

    return 0;
}