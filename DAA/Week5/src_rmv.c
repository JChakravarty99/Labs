#include<stdio.h>
#include<stdlib.h>


void source_removal(int adj_matrix[][100],int v)
{
	int count = 0;
	int visited[100] = {0};
	while(count < v)
	{
		for(int i=0;i<v;i++)
		{
			if(visited[i] == 1)
			{
				continue;
			}
			int flag = 0;
			for(int j=0;j<v;j++)
			{
				if(adj_matrix[i][j] == 1)
				{
					flag = 1;
				}
			}
			if(flag == 0)
			{
				printf("%d ",i);
				visited[i] = 1;
				for(int k=0;k<v;k++)
				{
					adj_matrix[k][i] = 0;
				}
				count++;
			}
		}
	}

}

int main()
{
	int v,e,adj_matrix[100][100]={0};
	printf("Enter the number of vertices : ");
	scanf("%d",&v);
	printf("Enter the number of edges : ");
	scanf("%d",&e);

	for(int i=0;i<e;i++)
	{
		int t1,t2;
		printf("Enter the vertices for edge : ");
		scanf("%d %d",&t1,&t2);
		adj_matrix[t1][t2] = 1;
	}

	source_removal(adj_matrix,v);

}