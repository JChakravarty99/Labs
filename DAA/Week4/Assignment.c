#include<stdio.h>
#include<stdlib.h>
int v;
int opcount;
void swap(int ans[], int a, int b)
{
	int temp = ans[a];
	ans[a] = ans[b];
	ans[b] = temp;
}

void permute(int arr[][v], int ans[], int l,int *min, int finans[])
{
	opcount++;
	if(l==v)
	{
		int sum = 0;
		for(int i=0; i<v; i++)
			sum += arr[i][ans[i]];
		if(sum<*min)
		{
			for(int i=0; i<v; i++)
				finans[i] = ans[i];
			*min = sum;
		}
		return;
	}             
	for(int i=l; i<v; i++)
	{
		swap(ans,i,l);
		permute(arr,ans,l+1,min,finans);
		swap(ans,i,l);
	}
}

void prob()
{
	opcount = 0;
	int min = 99999999;
	int arr[v][v];
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
			arr[i][j] = i+j;
	}
	int ans[v];
	for(int i=0; i<v; i++)
		ans[i] = i;
	int finans[v];
	permute(arr,ans,0,&min,finans);
	printf("\nFINALASSIGMT: ");
	for(int i=0; i<v; i++)
		printf("%d",finans[i]);
	printf("\n%d\n",opcount);
}

int main()
{
	for(int i=0; i<10; i++)
	{
		v = i+2;
		prob();
	}
	return 0;
}