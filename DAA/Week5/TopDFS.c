#include <stdio.h>
#include <stdlib.h>

void insert (int V[][20], int v1, int v2, int vertices)
{
	if(V[v1][v2] == 1 || v1 == v2)
		return;

	int value;
	printf("Enter value for edge %d and %d : ",v1, v2);
	scanf(" %d", &value);

	if(v1 > vertices - 1 || v2 > vertices -1 || v1 < 0 || v2 < 0)
	{
		return;
	}
	
	if(v1 == v2)
	{
		V[v1][v1] = 0;
		return;
	}

	V[v1][v2] = value;
	
}

void DFS(int i, int adj[][20], int visited[20], int n, int printed[20])
{
    int j;
    static int count = 0;
    visited[i]=1;
	printed[i] = 1;
	for(j=0;j<n;j++)
       if(!visited[j]&&adj[i][j]==1)
       {
            
            //printf("%d--%d\n",i, j);
            DFS(j, adj, visited, n, printed);
       }
    printed[count] = i;
    count++;
    //printf("%d\n",i);
}

int main()
{	
	int adj[20][20], visited[20], n, printed[20];
	int index = 0;
	//Entering no of vertices
	printf("enter no of vertices: ");
	scanf(" %d", &n);

	//setting adjacency matrix to 0
	for(int i =0; i<n; i++)
		for(int j = 0; j<n; j++)
			adj[i][j] = 0;

	//User enters adjacency matrix
	printf("Enter adj matrix: \n");
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			insert(adj, i, j, n);

	//Adjacency matrix is confirmed
	for(int i =0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
			printf(" %d ", adj[i][j]);
		printf("\n");
	}

	//Visited and printed matrix is set to 0
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
		printed[i] = 0;
	}

	//performing dfs
	DFS(2, adj, visited, n, printed);
	/*for(int i = 0; i<n; i++)
	{
		printf("%d %d\n",i, visited[i]);
	}*/
	for(int i = 0; i<n; i++)
	{
		if(!visited[i])
		{
			DFS(i, adj, visited, n, printed);
		}
	}

	for (int i = n-1; i >= 0; i--)
	{
		printf("%d\n", printed[i]);
	}
	return 0;
}