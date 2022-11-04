//Hashing--Linear Probing


#include<stdio.h>
#define MAX 10

void create(int a[]){
    for(int i=0;i<MAX;i++)
        a[i]=-1;
}

int hashing(int val){
    return val%MAX;
}

void lp(int a[],int val){
    for(int i=0;i<MAX;i++){
        int code=hashing(hashing(val)+i);
        if(a[code]==-1){
            a[code]=val;
            break;
        }
    }
}

void display(int a[]){
    printf("---------------------------------------\n");
    for(int i=0;i<MAX;i++){
        printf("| %d ",a[i]);
    }
    printf("\n---------------------------------------\n");
}

void main(){

    int n,choice,val;
    int a[MAX];
    printf("Enter the size of the array\n");
    scanf("%d",&n);

    create(a);

    for(int i=0;i<n;i++){

        printf("Enter the inserting element\n");
        scanf("%d",&val);

        lp(a,val);
        display(a);
                
    }    
}
