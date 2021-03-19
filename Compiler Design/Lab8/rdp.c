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
bool datatype();
void identifier_list();
void identifier_list_prime();
void identifier_list_prime_prime();
void statement();
void statement_list();
void expn();
void eprime();
void term();
void tprime();
void factor();
void relop();
void relop_prime();
void addop();
void mulop();
void simple_expn();
void seprime();

void report_error()
{
	printf("\n\nerror at line:%d and col:%d , expected :",s.row,s.col );
}

void Program()
{
	s=getnextToken(fa); printtok(s);
	// printf("token - %s\n",s.lexeme);
	if(!strcmp(s.lexeme,"main"))
	{
		// printf("here %s\n","i am" );
		s=getnextToken(fa); printtok(s);
		if(!strcmp(s.lexeme,"("))
		{
			s=getnextToken(fa); printtok(s);
			if(!strcmp(s.lexeme,")"))
			{
				s=getnextToken(fa); printtok(s);
				if(!strcmp(s.lexeme,"{"))
				{
					declartions();
					statement_list();
					s=getnextToken(fa); printtok(s);
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
	printtok(s);
	if(!strcmp(s.lexeme,"int") || !strcmp(s.lexeme,"char"))
	{
		identifier_list();
		s=getnextToken(fa); 
		printtok(s);
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
	printtok(s);
	if(s.lexeme[0]=='i'&&s.lexeme[1]=='d'&&s.lexeme[2]==' ')
	{
		identifier_list_prime();
	}
	else
	{
		report_error(); 
		printf(" identifier \n");
		exit(0);
	}
}

void identifier_list_prime()
{
     
	s=getnextToken(fa); 
	printtok(s);
	if(!strcmp(s.lexeme,","))
	{
		identifier_list();
	}
	else if(!strcmp(s.lexeme,"["))
	{
		identifier_list_prime_prime();
	}
	else
	{
		sanitize(s,fa);
	}

}

void identifier_list_prime_prime()
{
	s=getnextToken(fa); 
	printtok(s);
	if(!strcmp(s.lexeme,"num"))
	{
		s=getnextToken(fa);
		printtok(s);
		if(!strcmp(s.lexeme,"]"))
		{
			s=getnextToken(fa);
			printtok(s);
			if(!strcmp(s.lexeme,","))
				identifier_list();
			else
				sanitize(s,fa);   
		}
		else
		{
			report_error(); 
			printf("]\n");
			exit(0);
		}
	}
}

void statement_list()
{
	s=getnextToken(fa); 
	printtok(s);
	if(s.lexeme[0]=='i'&&s.lexeme[1]=='d'&&s.lexeme[2]==' ')
	{
		sanitize(s,fa);
		statement();
		statement_list();
	}
	else
		sanitize(s,fa);
}

void statement()
{
	assign_stat();
	s=getnextToken(fa); 
	printtok(s);
	if(!strcmp(s.lexeme,";"))
	{
		return ;
	}
	else
	{
		report_error(); 
		printf(";\n");
		exit(0);
	}
}

void assign_stat()
{
	s=getnextToken(fa); 
	printtok(s);
	if(s.lexeme[0]=='i'&&s.lexeme[1]=='d'&&s.lexeme[2]==' ')
	{
		s=getnextToken(fa); 
		printtok(s);
		if(!strcmp(s.lexeme,"="))
		{
			expn();
		}
		else
		{
			report_error(); 
			printf("=\n");
			exit(0);
		}
	}
	else
	{
		report_error(); 
		printf("identifier \n");
		exit(0);
	}
}

void expn()
{
	simple_expn();
	eprime();
}

void eprime()
{
	s=getnextToken(fa); 
	printtok(s);
	if(!strcmp(s.lexeme,"==")||!strcmp(s.lexeme,"!=")||!strcmp(s.lexeme,"<=")||!strcmp(s.lexeme,">=")||!strcmp(s.lexeme,"<")||!strcmp(s.lexeme,">"))
	{
		sanitize(s,fa);
		relop();
		simple_expn();
	}
	else
		sanitize(s,fa);
}

void simple_expn()
{
	term();
	seprime();
}

void seprime()
{
	s=getnextToken(fa); 
	printtok(s);
	if(!strcmp(s.lexeme,"+")||!strcmp(s.lexeme,"-"))
	{
		sanitize(s,fa);
		addop();
		term();
		seprime();
	}
	else
		sanitize(s,fa); 

}

void term()
{
	factor();
	tprime();
}

void tprime()
{
	s=getnextToken(fa); 
	printtok(s);
	if(!strcmp(s.lexeme,"*")||!strcmp(s.lexeme,"/")||!strcmp(s.lexeme,"%"))
	{
		sanitize(s,fa);
		mulop();
		factor();
		tprime();
	}
	else
		sanitize(s,fa); 
}

void factor()
{
	s=getnextToken(fa); 
	printtok(s);
	if((s.lexeme[0]=='i'&&s.lexeme[1]=='d'&&s.lexeme[2]==' ')|| !strcmp(s.lexeme,"num") ){
		return;
	}
	else
	{
		report_error(); 
		printf("identifier or number \n");
		exit(0);
	}
}

void relop()
{
	s=getnextToken(fa); 
	printtok(s);
	if(!strcmp(s.lexeme,"==") || !strcmp(s.lexeme,"!=") || !strcmp(s.lexeme,"<=") || !strcmp(s.lexeme,">=") || !strcmp(s.lexeme,"<") || !strcmp(s.lexeme,">") )
	{
		return;
	}
	else
	{
		report_error(); 
		printf(" relational operator \n");
		exit(0);
	}
}

void addop()
{
	s=getnextToken(fa); 
	printtok(s);
	if(strcmp(s.lexeme,"+")||strcmp(s.lexeme,"-"))
	{
		return;
	}
	else
	{
		report_error(); 
		printf(" + or - \n");
		exit(0);
	}
}

void mulop()
{
	s=getnextToken(fa); 
	printtok(s);
	if( !strcmp(s.lexeme,"*") || !strcmp(s.lexeme,"/") || !strcmp(s.lexeme,"%"))
	{
		return;
	}
	else
	{
		report_error();
		printf(" multiply and divide operator\n");
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
	printtok(s);
	if(!strcmp(s.lexeme,"end"))
	{
		printf("\n Successfully parsed \n");
	}
}