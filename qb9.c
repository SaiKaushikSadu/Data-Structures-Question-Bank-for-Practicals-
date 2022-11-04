//Some operations in singly linked list

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

struct node*insert_before_pos(struct node*head,int val,int pos){
    struct node*ptr;
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;

        ptr=head;
        pos--;
        while(pos!=2){
                ptr=ptr->next;
                pos--;
            }
            newnode->next=ptr->next;
            ptr->next=newnode;

    return head;
}

void search_node(struct node*head,int key){
    struct node*ptr;
    ptr=head;
    int val;
    while (ptr->next!=NULL){
        if(ptr->data==key){
            printf("Found\n");
            break;
        }
        else{
            ptr=ptr->next;
        }
    }
}

int count_nodes(struct node* head){
    int count=0;
    struct node*ptr;
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    return count;
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
    
    int choice,val,pos,key;

    do
    {
        printf("1.Create\n2.Insert_before_pos\n3.Count_nodes\n4.Search_nodes\n5.Display\n6.Exit\n");
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
            printf("Enter the pos before which you need to insert\n");
            scanf("%d",&pos);
            head=insert_before_pos(head,val,pos);
            break;

        case 3:
            printf("The total no of nodes in linked list are: %d\n",count_nodes(head));
            break;
        
        case 4:
            printf("Enter the val that you need to search\n");
            scanf("%d",&key);
            search_node(head,key);
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