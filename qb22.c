//Hashing --Quadratic probing

#include<stdio.h>
#define MAX 10

void create(int a[]){
    for(int i=0;i<MAX;i++){
        a[i]=-1;
    }
}

int hashing(int val){
    return val%MAX;
}

void qp(int a[],int val){
    for(int i=0;i<MAX;i++){
        int code=hashing(hashing(val)+i*i);
        if(a[code]==-1){
            a[code]=val;
            break;
        }
    }
}

void display(int a[]){
    for(int i=0;i<MAX;i++){
        printf("|%d ",a[i]);
    }
}

void main(){

    int n;
    int val;

    int a[MAX];
    create(a);

    printf("Enter the number of elements:\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        printf("---------------------------------------------\n");
        printf("Enter the element that you need to insert:\n");
        scanf("%d",&val);

        qp(a,val);
        display(a);
    }

}