//Some operations in BST
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*left;
    struct node*right;
};

struct node*root=NULL;

struct node*insert(struct node*root,int val){
    if(root==NULL){
        struct node*root=(struct node*)malloc(sizeof(struct node));
        root->data=val;
        root->left=NULL;
        root->right=NULL;
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

struct node*delete(struct node*root,int val){
    if(root==NULL){
        return root;
    }
    if(val<root->data){
        root->left=delete(root->left,val);
    }
    else if(val>root->data){
        root->right=delete(root->right,val);
    }
    else if(root->data==val){
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right=NULL){
            return root->left;
        }
        else{
            int minv;
            struct node*ptr=root->right;
            while(ptr!=NULL){
                minv=ptr->data;
                ptr=ptr->left;
            }
            root->data=minv;

            root->right=delete(root->right,minv);
        }
    }
}

void inorder(struct node*root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
}

void main(){

    int ch,val;

    do
    {
        printf("-------------------------------------------------------------\n");
        printf("1.Insertion\n2.Deletion\n3.Inorder\n4.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value that you need to insert\n");
            scanf("%d",&val);
            root=insert(root,val);
            break;

        case 2:
            printf("Enter the element that you need to delete\n");
            scanf("%d",&val);
            delete(root,val);
            break;

        case 3:
            printf("The inorder traversal is: \n");
            inorder(root);
            printf("\n");
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Enter a valid choice\n");
            break;
        }

    } while (ch<=4);
    
}
