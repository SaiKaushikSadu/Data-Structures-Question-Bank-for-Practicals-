//singly linked list(Insertion Operations)

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node*create(struct node* head){
    int num;
    struct node*ptr,*newnode;
    printf("Enter the num (-1 to exit):\n");
    scanf("%d",&num);

    while(num!=-1){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=num;
        //newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            newnode->next=NULL;
        }
        else{
            ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=NULL;
        }
        printf("Enter the data:\n");
        scanf("%d",&num);
    }
    return head;
}

struct node*insert_begin(struct node*head,int val){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;

    newnode->next=head;
    head=newnode;

    return head;
}

struct node*insert_end(struct node*head,int val){
    struct node* ptr=head;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;

    while (ptr->next!=NULL)
    {
       ptr=ptr->next; 
    }
    ptr->next=newnode;
    newnode->next=NULL;

    return head;
}

struct node*insert_pos(struct node*head,int val,int pos){
    struct node*ptr;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;

    if(pos==1){
        insert_begin(head,val);
    }
    else{
        ptr=head;
        while(pos!=2){
                ptr=ptr->next;
                pos--;
            }
            newnode->next=ptr->next;
            ptr->next=newnode;
    }  
    return head;
}

void display(struct node* head){
    struct node*ptr;
    ptr=head;

    if(ptr==NULL){
        printf("Linked list is empty\n");
    }
    else{
        while (ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}

void main(){
    struct node*head=NULL;
    
    int choice,val,pos;

    do
    {
        printf("1.Create\n2.Insert_begin\n3.Insert_end\n4.Insert_pos\n5.Display\n6.Exit\n");
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
            printf("Enter the val that you need to insert\n");
            scanf("%d",&val);
            printf("Enter the pos that you need to insert\n");
            scanf("%d",&pos);
            head=insert_pos(head,val,pos);
            break;

        case 5:
            display(head);
            printf("\n");
            break;
        
        case 6:
            exit(0);

        default:
        printf("Enter a valid choice\n");
            break;
        }
    } while (choice!=6);
    
}