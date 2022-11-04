//Stack using array

#include<stdio.h>
#define MAX 5

int stack[MAX];
int top=-1;

void push(int val){
    if(top==MAX)
        printf("Stack overflow\n");
    else{
        top++;
        stack[top]=val;
    }
}

int pop(){
    int val;
    if(top==-1){
        printf("Stack Undeflow\n");
        return -1;
    }
    else{
        val=stack[top];
        top--;
        return val;
    }
}

int peek(){
    int val;
    if(top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    else{
        val=stack[top];
        return val;
    }
}

void display(){
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}

void main(){
    int choice,data;
    int z;
    do{
        printf("1.PUSH\n 2.POP\n 3.PEEK\n 4.DISPLAY\n");
        printf("Enter your choice:\n");
        printf("----------------------\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data that you need to enter\n");
            scanf("%d",&data);
            push(data);
            break;

        case 2:
            printf("The popped element is: %d ",pop());
            printf("\n");
            break;

        case 3:
            printf("The top most element is : %d ",peek());
            printf("\n");
            break;

        case 4:
            display();
            printf("\n");
            break;
        
        default:
        printf("Enter a valid choice\n");
            break;
        }


        printf("Enter 1 to continue or 0 to exit\n");
        scanf("%d",&z);
    }while(z==1);
    
}