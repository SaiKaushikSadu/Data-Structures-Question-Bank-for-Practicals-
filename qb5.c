//circular queue using array
#include<stdio.h>
#define MAX 5

int rear=-1;
int front=-1;
int cqueue[MAX];

int isEmpty(){
    if(front==-1 || rear==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(){
    if((rear+1)%MAX==front){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int val){
    if((rear+1)%MAX==front){
        printf("Queue is Full\n");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        cqueue[rear]=val;
    }
    else{
        rear=(rear+1)%MAX;
        cqueue[rear]=val;
    }
}

int dequeue(){
    int val;
    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
        return -1;
    }
    else if(front==rear){
        val=cqueue[front];
        front=rear=-1;
        return val;
    }
    else{
        // if(front==MAX-1){
        //     val=cqueue[front];
        //     front=0;
        // }
        // else{
        //     val=cqueue[front];
        //     front++;
        // }
        val=cqueue[front];
        front=(front+1)%MAX;
        return val;
    }
}

int getrear(){
    if(isEmpty()){
        return -1;
    }
    else{
        return cqueue[rear];
    }
}

int getFront(){
    if(isEmpty()){
        return -1;
    }
    else{
        return cqueue[front];
    }
}

void display(){
    int i=front;
    if(front==-1 || rear==-1){
        printf("Queue is Empty!!\n");
    }
    else{
        while(i!=rear){
            printf("%d ",cqueue[i]);
            i=(i+1)%MAX;
        }
        printf("%d ",cqueue[rear]);
    }
}

void main(){

    int z,choice;
    int val,ans;
    do
    {
        printf("Choose the option which operation you need to perform:\n");
        printf("1.enqueue\n 2.dequeue\n 3.getrear\n 4.getFront\n 5.DISPLAY\n 6.isEmpty\n 7.isFull\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value that you need to insert\n");
            scanf("%d",&val);
            enqueue(val);
            printf("\n");
            break;
        
        case 2:
            val=dequeue();
            if(val!=-1){
                printf("The value popped out of the queue is %d",val);
            }
            printf("\n");
            break;

        case 3:
            val=getrear();
            if(val!=-1){
                printf("The value of rear element of the queue is %d",val);
            }
            printf("\n");
            break;

        case 4:
            val=getFront();
            if(val!=-1){
                printf("The value of front element of the queue is %d",val);
            }
            printf("\n");
            break;

        case 5:
            display();
            printf("\n");
            break;

        case 6:
            ans=isEmpty();
            if(ans==1){
                printf("Yes!!\n");
            }
            else{
                printf("NO!\n");
            }
            break;

        case 7:
            ans=isFull();
            if(ans==1){
                printf("Yes!!\n");
            }
            else{
                printf("NO!\n");
            }
            printf("\n");
            break;    

        default:
            printf("Choose a valid option..\n");
            break;
        }

        printf("Enter 1 to continue or 0 to exit\n");
        scanf("%d",&z);
    } while (z!=0);

}
