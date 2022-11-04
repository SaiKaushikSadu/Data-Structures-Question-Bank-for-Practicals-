//DFS-->Stack

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void dfs(int adj[MAX][MAX],int visited[],int start){

    int stack[MAX];
    int top=-1;
    printf("%c  ",start+65);
    visited[start]=1;
    int i;
    stack[++top]=start;
    while(top!=-1){
        start=stack[top];
        for(i=0;i<MAX;i++){
            if(adj[start][i] && visited[i]==0){
                stack[++top]=i;
                printf("%c  ",i+65);
                visited[i]=1;
                break;
            }
        }
        if(i==MAX){
            top--;
        }
    }
}

void main(){

    int adj[MAX][MAX];
    int visited[MAX]={0};
    int start;

    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            scanf("%d",&adj[i][j]);
        }
    }

    printf("Enter the starting node:\n");
    scanf("%d",&start);

    printf("The DFS traversal is :\n");
    dfs(adj,visited,start);
    printf("\n");

}
