#include<stdio.h>

//Simple input file for symbol table program
int sum(int a, int b)
{
	int s=a + b;
	return s;
}

bool search(int *arr,int key)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(arr[i]==key)
			return true;
		else 
			return false;
	}
}
//Driver function
void main()
{
	int a[20],i,res;
	bool status;
	printf("Enter array elements:");
	for(i=0;i<10;++i)
		scanf("%d",&a[i]);
	res=sum(a[0],a[4]);
	status=search(a,res);
	printf("%d",status);
}