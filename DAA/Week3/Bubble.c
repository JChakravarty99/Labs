#include<stdio.h>
#include <stdlib.h>
//plot with n vs opcount
int main()
{
	int choice, n, opcount, temp;
	int arr[100];
	do{
		printf("Enter number of elements: ");
		scanf(" %d", &n);
		printf("Enter %d numbers to sort: ", n);
		opcount = 0;
		temp = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf(" %d", &arr[i]);
		}

		printf("Entered array is: \n");
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", arr[i]);
		}

		printf("\nSorting now!");
		for (int i = 0; i < n-1; ++i)
		{
			for (int j = 0; j < n-i-1; ++j)
			{
				opcount++;
				if(arr[j] > arr[j+1])
				{
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		
		printf("\nSorted array is: \n");
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", arr[i]);
		}
		printf("\nOpcount is: %d", opcount);
		printf("\nDo you wish to continue? (1/0): ");
		scanf(" %d", &choice);
	}while(choice != 0);
	return 0;
	
}