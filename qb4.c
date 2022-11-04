//queue using array

#include<stdio.h>
#define MAX 5

int queue[MAX];
int rear=-1;
int front=-1;

void enqueue(int val){
    if(rear==MAX-1){
        printf("Queue is Full");
    }
    else if(rear==-1 && front==-1){
        front=rear=0;
        queue[rear]=val;
    }
    else{
        rear++;
        queue[rear]=val;
    }
}

int dequeue(){
    int val;
    if(rear==-1 || front>rear){
        printf("Queue is Empty\n");
        return -1;
    }
    else if(front==rear){
        val=queue[front];
        rear=front=-1;
        return val;
    }
    else{
        val=queue[front];
        front++;
        return val;
    }
}

int getFront(){
    if(front==-1 || front>rear){
        printf("Queue is Empty\n");
        return -1;
    }
    else{
        return queue[front];
    }
}

int getrear(){
    if(front==-1 || front>rear){
        printf("Queue is Empty\n");
        return -1;
    }
    else{
    return queue[rear];
    }
}

int isFull(){
    if(rear==MAX-1){
        //printf("Queue is FUll\n");
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(){
    if(front==-1 || front>rear){
        //printf("Queue is Empty\n");
        return 1;
    }
    else{
        return 0;
    }
}

void display(){
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}

void main(){

    int z,choice;
    int val,ans;
    do
    {
        printf("Choose the option which operation you need to perform:\n");
        printf("1.enqueue\n2.dequeue\n3.getrear\n4.getFront\n5.DISPLAY\n6.isEmpty\n7.isFull\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the val that you need to insert\n");
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
    } while (z==1);

}

