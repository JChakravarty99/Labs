#include<stdio.h>
#include <stdlib.h>
#include <string.h>
//plot strlen(str+substr) vs opcount
int string_match(char str[100], char substr[100])
{
	int status = 1;
	int match = 0;
	int opcount = 0;
	int len = strlen(substr);
	for (int i = 0; str[i] !='\0'; i++)
	{
		opcount++;
		if(str[i+1] == '\0' && match == 0)
		{
			status = 0;
			break;
		}

		if(str[i] == substr[0])
		{
			match ++;
			for (int j = 1; substr[j] != '\0'; j++)
			{
				opcount++;
				if(str[i+j] != substr[j])
				{
					status = 0;
					break;
				}
			}
			if(match == 1 && status == 1)
				break;
		}
	}
	printf("\nopcount is: %d", opcount);
	return status;
}


void main()
{
	char str[100], substr[100];
	printf("Enter string: ");
	scanf("%s", str);
	printf("Enter substring: ");
	scanf("%s", substr);
	int lstr = strlen(str);
	int lsub = strlen(substr);
	printf("\nsum of lengths = %d", lstr+lsub);
	int status = string_match(str, substr);
	if(status == 1)
		printf("\nsubstring found!\n");
	else
		printf("\nsubstring not found!\n");
}