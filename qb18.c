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

int height(struct node*root){
    int rheight,lheight;

    if(root==NULL){
        return 0;
    }
    else{
        lheight=height(root->left);
        rheight=height(root->right);
        if(lheight>rheight){
            return lheight+1;
        }
        else if(rheight>lheight){
            return rheight+1;
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

void preorder(struct node*root){
    if(root==NULL){
        return;
    }
    printf("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node*root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->data);
}

void main(){

    int ch,val;

    do
    {
        printf("\n-------------------------------------------------------------\n");
        printf("1.Insertion\n2.Traversals\n3.Height of the tree\n4.Exit\n");
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
            printf("The postorder traversal is: \n");
            postorder(root);
            printf("\n");
            printf("The preorder traversal is: \n");
            preorder(root);
            printf("\n");
            printf("The inorder traversal is: \n");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("The height of the tree is :%d ",height(root));
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
