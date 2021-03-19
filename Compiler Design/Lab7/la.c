#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>

#define SZ 20

struct token
{
  char tok_type[SZ];
  char lexeme[SZ];
  int row,col,idx;
  int sz;
};

struct ListElement
{
  struct token tok;
  struct ListElement *next;
};

struct ListElement *TABLE[SZ];
int row=1,col=1,val=-1,TableLength = 0;
char dbuff[SZ];
bool FILENOTENDED=true;

char keyword[34][10]={"printf","scanf","auto","double","int",
                        "struct","break","else","long","switch","case","enum","register",
                        "typedef","char","extern","return","union","continue",
                        "for","signed","void","do","if","static","while","default","goto",
                        "sizeof","volatile","const","float","short","unsigned"};


bool iskeyword(char* buf)
{
   for(int i=0;i<34;i++)
   {
   	 if(strcmp(keyword[i],buf)==0)
   	 	return true;
   }
   return false;
}

bool isDelimiter(char ch)
{
	 if (ch == ',' || ch == ';'  || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return true;
    return false;
}

bool isArithmetic_operator(char ch)
{
    if (ch == '%' || ch == '+' || ch == '-' || ch == '*' || ch == '/' )
        return true;
    return false;
}

void printtok(struct token t)
{
   printf("<%s,%d,%d> ",t.lexeme,t.row,t.col-1);
}

int SEARCH(struct token tk)
{
    //printf("s\n");
    struct ListElement * cur;
    for(int i=0;i<=val;i++)
    {
        cur = TABLE[i];
        if(cur&&strcmp(tk.tok_type,"func")==0)
        {
            if(strcmp((cur->tok).lexeme,tk.lexeme)==0)
            {
                return 1;
            }
        }
        else
        {
            while(cur)
            {
                if(strcmp((cur->tok).lexeme,tk.lexeme)==0&&strcmp((cur->tok).tok_type,tk.tok_type)==0&&(cur->tok).idx==tk.idx)
                {
                    return 1;
                }
                cur=cur->next;
            }
        }
    }
    return 0;
}

void INSERT(struct token tk)
{
    if(strcmp(tk.tok_type,"func")!=0&&SEARCH(tk)==1)
    {
        return;
    }

    struct ListElement* cur = malloc(sizeof(struct ListElement));
    cur->tok = tk;
    cur->next = NULL;

    if(TABLE[val]==NULL)
    {
        TABLE[val] = cur; // No collosion.
    }
    else
    {
        struct ListElement * ele= TABLE[val];
        while(ele->next!=NULL)
        {
            ele = ele->next; // Add the element at the End in the case of a collision.
        }
        ele->next = cur;
    } 
}

void sanitize(struct token s,FILE * fa) 
{
    int len;
    if(s.lexeme[0]=='i'&&s.lexeme[1]=='d'&&s.lexeme[2]==' ')
        len=strlen(s.lexeme)-3;
    else len=strlen(s.lexeme);
        fseek(fa,-1*len,SEEK_CUR);
}

struct token getnextToken(FILE *fa)
{
    char ca,cb;
    int i,j;
    char buf[SZ],temp[SZ];
    struct token s;
    ca=fgetc(fa);
    while(ca!=EOF)
    {
    	//newline
    	if(ca=='\n')
        {
    		row++;
    		col=1;
    		//printf("\n");
    	}
    	//blank space and tabs
    	else if(ca==' '||ca=='\t')
        {
    		  col++;
              while(ca==' '||ca=='\t')
                   ca=fgetc(fa);
              fseek(fa,-1,SEEK_CUR);
    	}
        //comments
        else if(ca=='/')
        {
            col++;
        	cb=fgetc(fa);
        	if(cb=='/')
            {
                 while(ca!='\n')
                  ca=fgetc(fa);
                 fseek(fa,-1,SEEK_CUR);
        	}
        	else if(cb=='*')
            {
                    do
                    {
                    	while(ca!='*')
                    		ca = fgetc(fa);
                    	ca = fgetc(fa);
                    }while(ca!='/');
        	}
        	else
            {
        		i=0;
                while(ca!='\n')
                {
                	temp[i++] = ca;
                	ca = fgetc(fa);
                }
                temp[i]='\0';
                strcpy(s.lexeme,"syntax error");
                s.row=row;
                s.col=col;
                fseek(fa,-1,SEEK_CUR);
                return s;
        	}
        }
        //preprocessor
        else if(ca=='#')
        {
        	i=0;
            while(ca!='\n')
            {
        	   temp[i++]=ca;
        	   ca=fgetc(fa);
            }
            temp[i]='\0';
            fseek(fa,-1,SEEK_CUR);
            if(strstr(temp,"#include")==NULL && strstr(temp,"#define")==NULL)
            {//not working
                printf("include\n");
                strcpy(s.lexeme,"syntax error");
                s.row=row;
                // row++;
                s.col=col;
                return s;
            }
        }
        //keywords and identifiers
        else if(isalpha(ca)||ca=='_')
        {
        	i=0;
        	while(isalnum(ca)||ca=='_')
            {
                buf[i++]=ca;
                ca=fgetc(fa);
                col++;
        	}
        	buf[i]='\0';
        	fseek(fa,-1,SEEK_CUR);

        	if(iskeyword(buf))
            {
                strcpy(s.lexeme,buf);
                strcpy(dbuff,buf);
                s.row=row;
                s.col=col-strlen(buf)+1;
                return s;
        	}
        	else
            {
                if(ca=='(')
                {
                    strcpy(s.lexeme,buf);
                    strcpy(s.tok_type,"func");
                    s.sz=-1;
                    if(SEARCH(s)==0)
                    {
                        val++;
                    }
                    s.idx = val;
                    INSERT(s);
                    return s;
                }
                char w[10]="";
                strcat(w,"id ");
                strcat(w,buf);
                strcpy(s.lexeme,w);
                strcpy(s.tok_type,dbuff);
                s.row=row;
                s.col=col-strlen(buf)+1;
 
                if(strcmp(dbuff,"int")==0)
                    s.sz=sizeof(int);
                else if(strcmp(dbuff,"char")==0)
                    s.sz=sizeof(char);
                else if(strcmp(dbuff,"bool")==0)
                    s.sz=sizeof(bool);
                else
                    s.sz=0;
                if(strcmp(dbuff,"return")==0||strcmp(dbuff,"if")==0||strcmp(dbuff,"scanf")==0||strcmp(dbuff,"printf")==0||strcmp(dbuff,"for")==0)
                    return s;
                s.idx=val;
                INSERT(s);

                return s;
        	}
        }
        //relational operator
        else if(ca=='='||ca=='>'||ca=='<'||ca=='!')
        {
        	cb=fgetc(fa);
        	i=0;
        	temp[i++]=ca;
            col++;
        	if(cb=='=')
            {
                temp[i++] = cb;
                temp[i] = '\0';
                strcpy(s.lexeme,temp);
                s.row=row;
                s.col=col;
                col++;
                return s;
        	}
        	else
            {
                temp[i]='\0';
                strcpy(s.lexeme,temp);
              	s.row=row;
              	s.col=col;
                fseek(fa,-1,SEEK_CUR);
              	return s;
        	}
        }
        //string
        else if(ca=='"')
        {
            i=0;
            do{
                col++;
             	i++;
             	ca=fgetc(fa);
            }while(ca!='"');
            col++;
            strcpy(s.lexeme,"string literal");
            s.row=row;
            s.col=col-i;
            return s;
        }
        //delimiters
        else if(isDelimiter(ca))
        {
            i=0;
        	temp[i++]=ca;
        	temp[i]='\0';
        	col++;
            strcpy(s.lexeme,temp);
            s.row=row;
            s.col=col;
            return s;
        }
        //numeric constants
        else if(isdigit(ca))
        {
        	i=0;
        	while(isdigit(ca))
            {
        		col++;
        		i++;
        		ca=fgetc(fa);
        	}
        	fseek(fa,-1,SEEK_CUR);
        	strcpy(s.lexeme,"num");
            s.row=row;
            s.col=col-i+1;
            return s;
        }
        //arithmetic op
        else if(isArithmetic_operator(ca))
        {
        	i=0;
        	temp[i++]=ca;
            temp[i]='\0';
        	col++;
            strcpy(s.lexeme,temp);
            s.row=row;
            s.col=col;
            return s;
        }
        ca=fgetc(fa);
    }
    strcpy(s.lexeme,"end");
    return s;
}

void Initialize()
{
    for(int i=0;i<SZ;i++)
    {
        TABLE[i] = NULL;
    }
}

void Display()
{
//iterate through the linked list and display
    for(int i=0;i<=val;i++)
    {
        struct ListElement * cur = TABLE[i];
        printf("%d %s %s\n\n",i+1,(cur->tok).lexeme,(cur->tok).tok_type);
        cur=cur->next;
        while(cur)
        {
            printf("%s   %s   %d\n",(cur->tok).lexeme, (cur->tok).tok_type,(cur->tok).sz);
            cur=cur->next;
        }
        printf("*******************\n");
    }
}