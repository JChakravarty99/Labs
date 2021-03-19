#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
S -> (L) | a
L -> L,S | S

Removing left recursion:
L -> SL'
L' -> ,SL' | epsilon
*/

int curr = 0;
char str[100];

void invalid() 
{
	printf("--------- ERROR ----------\n");
	exit(0);
}

void valid() 
{
	printf("--------- SUCCESS ----------\n");
	exit(0);
}

void S();
void L();
void Lprime();

void S() 
{
	if (str[curr] == '(') 
	{
		curr++;
		L();
		if (str[curr] == ')') 
		{
			curr++;
			return;
		}
		else invalid();
	}
	else if (str[curr] == 'a') 
	{
		curr++;
		return;
	}
	else invalid();
}

void L() 
{
	S();
	Lprime();
}

void Lprime() 
{
	if (str[curr] == ',') 
	{
		curr++;
		S();
		Lprime();
	}
}

void main() 
{
	printf("Enter String: ");
	scanf("%s", str);
	S();
	if(str[curr] == '$')
		valid();
	else
		invalid();
}





