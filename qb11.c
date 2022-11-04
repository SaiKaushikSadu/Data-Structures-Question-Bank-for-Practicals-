//circular linked list(Deletion Operations)
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

struct node* delete_begin(struct node* head){
    struct node*ptr;
    
    ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    ptr->next=head->next;
    free(head);
    head=ptr->next;

    return head;
}

struct node* delete_end(struct node * head){
    struct node*ptr,*prev;
    
    ptr=head;
    while(ptr->next!=head){
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=ptr->next;
    free(ptr);

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
        printf("1.Create\n2.delete_begin\n3.delete_end\n4.Display\n5.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            head=create(head);
            break;

        case 2:
            head=delete_begin(head);
            break;

        case 3:
            head=delete_end(head);
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
