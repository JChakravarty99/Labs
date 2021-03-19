#include <stdio.h>
#include <stdlib.h>

int v,e;

void bfs(int visited[], int adm[][v], int s)
{
    int queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = s;
    visited[s] = 1;
    while(front!=rear)
    {
        int ff = queue[front++];
        for(int i=0; i<v; i++)
        {
            if(!visited[i]&&adm[ff][i])
            {
                visited[i] = 1;
                printf("%d==%d   ",ff,i);
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    printf("Enter v: ");
    scanf("%d",&v);
    printf("Enter e: ");
    scanf("%d",&e);
    int adm[v][v];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
            adm[i][j] = 0;
    }
    for(int i=0; i<e; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        adm[a][b] = 1;
    }
    printf("****************\n");
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
            printf("%d ",adm[i][j]);
        printf("\n");
    }
    printf("****************\n");
    int visited[v];
    for(int i=0; i<v; i++)
        visited[i] = 0;
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
            bfs(visited,adm,i);
    }
    return 0;
}