//BFS-->Queue

#include<stdio.h>
#define MAX 5

void bfs(int adj[MAX][MAX],int visited[MAX],int start){

    int queue[MAX];
    int rear=-1;
    int front =-1;
    int i;

    queue[++rear]=start;
    visited[start]=1;

    while (rear!=front)
    {   
        start=queue[++front];
        printf("%c ",start+65);

        for(int i=0;i<MAX;i++){
            if(adj[start][i] && visited[i]==0){
                queue[++rear]=i;
                visited[i]=1;
            }
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

    printf("Enter the start point:\n");
    scanf("%d",&start);
    
    printf("The BFS traversal is :\n");
    bfs(adj,visited,start);

}