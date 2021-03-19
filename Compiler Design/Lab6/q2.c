#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
S -> UVW
U -> (S) | aSb | d
V -> aV | ε
W -> cW | ε
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
void U();
void V();
void W();

void S() 
{
	U();
	V();
	W();
}

void U() 
{
	if (str[curr] == '(') {
		curr++;
		S();
		if (str[curr] == ')') {
			curr++;
			return;
		}
		else invalid();
	}
	else if (str[curr] == 'a') {
		curr++;
		S();
		if (str[curr] == 'b') {
			curr++;
			return;
		}
		else invalid();
	}
	else if (str[curr] == 'd') {
		curr++;
		return;
	}
	else invalid();
}

void V() 
{
	if (str[curr] == 'a') {
		curr++;
		V();
	}
}

void W() 
{
	if (str[curr] == 'c') {
		curr++;
		W();
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
