//singly linked list(Deletion Operations)

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node*create(struct node* head){
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
            newnode->next=NULL;
            head=newnode;
        }
        else{
            ptr=head;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=NULL;
        }
        printf("Enter the num\n");
        scanf("%d",&num);
    }
    return head;
        
}

struct node* delete_begin(struct node* head){
    struct node* ptr;
    if(head==NULL){
        printf("The list is already empty\n");
    }
    else{
        ptr=head;
        head=head->next;
        free(ptr);
    }
    return head;
}

struct node*delete_end(struct node*head){
    struct node*ptr,*prev;
    if(head==NULL){
        printf("LL is empty\n");
        return head;
    }
    else{
        ptr=head;
        while(ptr->next!=NULL){
            prev=ptr;
            ptr=ptr->next;
        }
        prev->next=NULL;
        free(ptr);
        ptr=NULL;
        return head;
    }
}

struct node*delete_pos(struct node*head,int pos){
    struct node*current,*prev;
    if(head==NULL){
        printf("The list is already empty!\n");
    }
    else{
        current=head;
        while (pos!=1)
        {
            prev=current;
            current=current->next;
            pos--;
        }
        prev->next=current->next;

        free(current);
        current=NULL;         
    }
    return head;
}

void display(struct node* head){
    struct node*ptr;

    if(head==NULL){
        printf("Linked list is empty\n");
    }
    else{
        ptr=head;
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
        printf("1.Create\n2.Delete_begin\n3.Delete_end\n4.Delete_pos\n5.Display\n6.Exit\n");
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
            printf("Enter the pos that you need to delete\n");
            scanf("%d",&pos);
            head=delete_pos(head,pos);
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