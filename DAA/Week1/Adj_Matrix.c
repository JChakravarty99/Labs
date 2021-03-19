#include<stdio.h>
#include<stdlib.h>

void insert (int V[][10], int v1, int v2, int vertices)
{
	if(v1 > vertices - 1 || v2 > vertices -1 || v1 < 0 || v2 < 0)
	{
		printf("Wrong input, enter again\n");
		return;
	}
	
	if(v1 == v2)
	{
		V[v1][v1] = 0;
		return;
	}
	
	V[v1][v2] = 1;
	V[v2][v1] = 1;
}

void print(int V[][10], int vertices)
{
	for(int i =0; i<vertices; i++)
	{
		for(int j = 0; j<vertices; j++)
				printf(" %d ", V[i][j]);
		printf("\n");
	}
}

void main()
{
	int vertices, choice;
	printf("Enter number of vertices: \n");
	scanf(" %d", &vertices);
	int V[10][10];
	int v1, v2;

	for(int i =0; i<vertices; i++)
		for(int j = 0; j<vertices; j++)
			V[i][j] = 0;

	for(int i =0; i<vertices; i++)
	{
		for(int j = 0; j<vertices; j++)
			printf(" %d ", V[i][j]);
		printf("\n");
	}

	do{
		printf("1.Enter edge\n2.Display Matrix\n");
		scanf(" %d", &choice);
		switch(choice)
		{
			case 1: printf("Enter source and dest: \n");
					scanf("%d %d", &v1, &v2);
					insert(V, v1, v2, vertices);
					break;

			case 2: print(V, vertices);
					break;
		}
	}while(choice < 3 && choice > 0);
}