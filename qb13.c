//stack using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head;

void push(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;

    if(head==NULL){
        newnode->next=NULL;
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}

void pop(){
    int val;
    struct node*ptr=head;
    if(head==NULL){
        printf("Stack underflow\n");
    }
    else{
        val=head->data;
        ptr=head;
        head=head->next;
        free(ptr);
        printf("Item popped is %d :\n",val);
    }
}

void peek(){
    printf("The peek element is :%d \n",head->data);
}

void display(){
    struct node*ptr;
    ptr=head;
    if(ptr==NULL){
        printf("Stack is empty\n");
    }
    else{
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

void main(){

    int val;
    int choice;

    do
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value that you need to push\n");
            scanf("%d",&val);
            push(val);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
        
        default:
            break;
        }
    } while (choice!=5);

}
