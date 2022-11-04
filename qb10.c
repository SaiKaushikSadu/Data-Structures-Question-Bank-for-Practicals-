//circular linked list(Insertion)
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};

struct node* create(struct node* head){
    struct node*ptr;
    struct node*newnode;
    int num;
    printf("Enter the num (-1 to exit):\n");
    scanf("%d",&num);

    while(num!=-1){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        newnode->next=NULL;

        if(head==NULL){
            newnode->next=newnode;
            head=newnode;
        }
        else{
            ptr=head;
            while(ptr->next!=head){
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=head;
        }
        printf("Enter the num\n");
        scanf("%d",&num);
    }
    return head;
}

struct node* insert_begin(struct node* head,int val){
    struct node*ptr;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=head;
    head=newnode;
    return head;
}

struct node* insert_end(struct node * head,int val){
    struct node*ptr;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    newnode->data=val;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=head;
    head=newnode;
    return head;
}

void display(struct node*head){
    struct node* ptr;
    ptr=head;

    while(ptr->next!=head){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
}

void main(){
    struct node*head=NULL;
    
    int choice,val;

    do
    {
        printf("1.Create\n2.Insert_begin\n3.Insert_end\n4.Display\n5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            head=create(head);
            break;

        case 2:
            printf("Enter the val that you need to insert\n");
            scanf("%d",&val);
            head=insert_begin(head,val);
            break;

        case 3:
            printf("Enter the val that you need to insert\n");
            scanf("%d",&val);
            head=insert_end(head,val);
            break;

        case 4:
            display(head);
            printf("\n");
            break;
        
        case 5:
            exit(0);

        default:
        printf("Enter a valid choice\n");
            break;
        }
    } while (choice!=5);
    
}
