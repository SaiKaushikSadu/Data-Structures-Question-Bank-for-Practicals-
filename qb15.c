//Some operations in BST
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};

struct node* root=NULL;

struct node *insert(struct node*root,int val){

    if(root==NULL){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->data=val;
    root->left=root->right=NULL;
    return root;
    }
    if(val>root->data){
        root->right=insert(root->right,val);
    }
    else if(val<root->data){
        root->left=insert(root->left,val);
    }
    return root;
}

void preorder(struct node*root){
    if(root==NULL){
        return;
    }
    printf("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);
}

int search(struct node* root,int val){
    if(root==NULL){
        return 0;
    }
    else if(val==root->data){
        return root->data;
    }
    else if(val>root->data){
        search(root->right,val);
    }
    else if(val<root->data){
        search(root->left,val);
    }
}

int total_nodes(struct node*root){
    if(root==NULL){
        return 0;
    }
    else{
        return (total_nodes(root->right)+total_nodes(root->left)+1);
    }
}

void main(){

    int ch,val;

    do{
        printf("--------------------------------------------------------------------\n");
        printf("1.Insertion\n2.Search\n3.Preorder traversal\n4.Total nodes in bst\n5.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value that you need to insert\n");
            scanf("%d",&val);
            root=insert(root,val);
            //preorder(root);
            break;

        case 2:
            printf("Enter the value that you need to search\n");
            scanf("%d",&val);
            if(search(root,val)==0)
                printf("Element not found\n");
            else
                printf("Element is found\n");
            break;

        case 3:
            printf("The preorder traversal is:\n");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("The total number of nodes in bst are :%d \n" ,total_nodes(root));
            break;
        
        case 5:
            exit(0);
            break;

        default:
            printf("Enter a valid choice\n");
            break;
        }

    }while(ch<=5);

}