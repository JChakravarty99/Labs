#include<stdio.h>
#include <stdlib.h>
int main()
{
	int OPCOUNT = 0;
	int m,n;
	for(int i=0; i<5; i++)
	{
		printf("Enter two nos: ");
		scanf(" %d %d", &m, &n);
		int t = m<n?m:n;
		if(t<2)
			t = 2;
		int soe[t+1];
		soe[0] = 0;
		soe[1] = 0;
		soe[2] = 1;
		for(int i=2;i<=t;i++)
			soe[i] = 1;
		for(int i=2;i*i<=t; i++)
		{
			if(soe[i])
			{
				for(int j=i*i;j<=t;j+=i)
				{
					OPCOUNT++;
					soe[j] = 0;
				}
			}
		}
		int ans = 1;
		for(int i=0; i<=t; i++)
		{
			if(soe[i])
			{
				int flaga = 1, flagb = 1;
				while(m%(flaga*i)==0)
				{
					OPCOUNT++;
					flaga *= i;
				}
				while(n%(flagb*i)==0)
				{
					OPCOUNT++;
					flagb *= i;
				}
				// printf("%d => %d %d\n",i,flaga, flagb);
				int min = flaga<flagb?flaga:flagb;
				ans = ans*min;
			}
		}
		// printf("==============================\n");
		printf("Gcd: of %d %d is %d\n",m,n,ans);
		printf("m+n is: %d\n", m+n);
		printf("OPERATIONS: %d\n",OPCOUNT);
		printf("\n");

	}
	return 0;
}