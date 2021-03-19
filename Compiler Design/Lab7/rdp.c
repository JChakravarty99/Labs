#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "la.c"

struct token s;
FILE * fa;

void declartions();
void assign_stat();
void assign_stat_prime();
bool datatype();
void identifier_list();
void identifier_list_prime();

void report_error()
{
	printf("error at line:%d and col:%d , expected :",s.row,s.col );
}



void Program()
{
	s=getnextToken(fa);
	// printf("token - %s\n",s.lexeme);
	if(!strcmp(s.lexeme,"main"))
	{
		// printf("here %s\n","i am" );
		s=getnextToken(fa);
		if(!strcmp(s.lexeme,"("))
		{
			s=getnextToken(fa);
			if(!strcmp(s.lexeme,")") )
			{
				s=getnextToken(fa);
				if(!strcmp(s.lexeme,"{"))
				{
					declartions();
					assign_stat();
					s=getnextToken(fa);
					if(!strcmp(s.lexeme,"}"))
					{
						// printf("line 39\n");
						return ;
					}
					else
					{
						report_error(); 
						printf("}\n");
						exit(0);
					}
				}
				else
				{
					report_error(); 
					printf("{\n");
					exit(0);
				}
			}
			else
			{
				report_error(); 
				printf(")\n");
				exit(0);
			}
		}
		else
		{
			report_error(); 
			printf("(\n");
			exit(0);
		}
	}
	else
	{
		report_error(); 
		printf("main\n");
		exit(0);
	}
}

void declartions()
{
	s=getnextToken(fa);
	if(!strcmp(s.lexeme,"int") || !strcmp(s.lexeme,"char"))
	{
		identifier_list();
		s=getnextToken(fa);
		if(!strcmp(s.lexeme,";"))
		{
			declartions();
		}
		else
		{
			report_error(); 
			printf(";\n");
			exit(0);
		}
	}
	else
	{
		sanitize(s,fa);
	}
}

void identifier_list()
{
	s=getnextToken(fa);
	if((s.lexeme[0]=='i'&&s.lexeme[1]=='d'&&s.lexeme[2]==' '))
	{
		identifier_list_prime();
	}
	else
	{
		report_error();
		printf("identifier \n");
		exit(0);
	}
}

void identifier_list_prime()
{
	s=getnextToken(fa);
	if(!strcmp(s.lexeme,","))
	{
		identifier_list();
	}
	else if(!strcmp(s.lexeme,";"))
	{
		sanitize(s,fa);
	}
	else
	{
		report_error(); printf(",\n");
		exit(0);
	}
}

void assign_stat()
{
	s=getnextToken(fa);
	if((s.lexeme[0]=='i'&&s.lexeme[1]=='d'&&s.lexeme[2]==' '))
	{
		s=getnextToken(fa);
		if(!strcmp(s.lexeme,"="))
		{
			assign_stat_prime();
		}
		else
		{
			report_error(); printf("=\n");
			exit(0);
		}
	}
	else
	{
		report_error(); printf("identifier \n");
		exit(0);
	}
}

void assign_stat_prime()
{
	s=getnextToken(fa);
	if((s.lexeme[0]=='i'&&s.lexeme[1]=='d'&&s.lexeme[2]==' ') || !strcmp(s.lexeme,"num") )
	{
		s=getnextToken(fa);
		if(!strcmp(s.lexeme,";"))
		{
			return ;
		}
		else
		{
			report_error(); printf(";\n");
			exit(0);
		}
	}
	else
	{
		report_error(); printf(" identifier or number \n");
		exit(0);
	}
}

bool datatype()
{
	s=getnextToken(fa);
	if(!strcmp(s.lexeme,"int") || !strcmp(s.lexeme,"char"))
	{
		return 1;
	}
	else
	{
		report_error(); printf(" datatype \n");
		exit(0);
	}
}

int main()
{
	fa = fopen("input.txt","r");
	if(fa==NULL)
	{
		perror("fopen");
		exit(0);
	}
	Program();
	s=getnextToken(fa);
	if(!strcmp(s.lexeme,"end"))
	{
		printf("\n Code parsed successfully\n");
	}
}