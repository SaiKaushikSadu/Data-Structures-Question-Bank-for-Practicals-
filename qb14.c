//queue using linked list

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int val){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    
    if(front==NULL && rear==NULL){
        front=rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(int val){
    struct node * ptr;
    ptr=front;
    if(front==NULL && rear==NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("Deleted eleemnt is: %d \n",ptr->data);
        front=front->next;
        free(ptr);
    }
}

void peek(){
    if(front==NULL && rear==NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("The topmost element is %d \n",front->data);
    }
}

void display(){
    struct node* ptr;
    if(front==NULL && rear==NULL){
        printf("Queue is empty\n");
    }
    else{
        ptr=front;
        while(ptr!=0){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

void main(){

    int choice,val;
    
    do
    {
        printf("1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value:\n");
            scanf("%d",&val);
            enqueue(val);
            break;

        case 2:
            printf("Enter the value:\n");
            scanf("%d",&val);
            dequeue(val);
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
            printf("Enter a valid choice\n");
            break;
        }


    } while (choice!=5);
    
}