#include<stdio.h>
#include <stdlib.h>

int GCD(int m, int n)
{
	int opcount = 0;
	int t = (m < n)?m:n;
	while(t>0)
	{
		opcount++;
		if(m%t == 0 && n%t==0)
			break;
		t = t-1;
	}
	printf("OPcount is: %d\n", opcount);
	return t;
}

int main()
{
	int choice,gcd, m ,n;
	do{
		printf("Enter two nos: ");
		scanf(" %d %d", &m, &n);
		gcd = GCD(m, n);
		printf("\nGcd of %d and %d is: %d\n",m, n, gcd);
		printf("m+n = %d\n", m+n);
		printf("Do you wish to continue? (1 - Yes/0 - No): ");
		scanf(" %d", &choice);
	}while(choice != 0);
	return 0;
}