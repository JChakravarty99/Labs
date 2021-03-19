#include<stdio.h>
#include<stdlib.h>
#include <string.h>
//Don't write print statements
int horspool(char str[], char substr[])
{
	int len = strlen(substr);
	int strlength = strlen(str);
	int table[10] = {0};
	printf("String: %s\n",str);
	printf("Substring: %s\n",substr);
	int status = 0;
	for(int i = 0; substr[i+1] != '\0'; i++)
		table[i] = len-i-1;

	int i = len-1;
	for(int j = len-1; j>=0; j--)
	{
		printf("\nComparing %c and %c\n",str[i], substr[j]);
		if(str[i] == substr[j])
		{
			printf("\nComparing %c and %c", str[i], substr[j]);
			i--;
			printf("\nValue of i is: %d", i);
			status = 1;
		}
		else
		{
			int temp = i;
			for(int k = 0; k < len; k++)
			{
				if(str[i] == substr[k])
					i = i + table[k];
			}
			if(i == temp)
			{
				i = i+len;
			}
			if(i >= strlength)
				break;
			printf("Shifting substr to %c\n",str[i]);
			j = len;
		}
	}
	return status;
}

void main()
{
	char str[100];
	char substr[100];
	printf("Enter string: ");
	scanf("%s", str);
	printf("\nEnter substring(len<10): ");
	scanf("%s", substr);
	int status = horspool(str, substr);
	printf("\nStatus is: %d\n",status);
}