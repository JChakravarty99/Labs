#include<stdio.h> 
#include<stdlib.h> 
#include<ctype.h> 
#include<string.h> 

void printupper(char buf[]) 
{ 
	for(int i=0;buf[i]!='\0';i++) 
		printf("%c",toupper(buf[i])); 
	printf("\n"); 
} 

int main() 
{ 
	char keyw[50][10]={"if","else","for","break","switch","case","default","do","while", "return","void","int","float","char","double","long","define","include","continue","\0"}; 
	char buf[10], filename[100]; 
	int ca,cb,i; 
	FILE *fa; 
	
	printf("\nEnter filename:");
    scanf("%s",filename);
    fa=fopen(filename,"r");
	//checking filestream integrity
	if(fa==NULL) 
	{ 
		printf("Cannot open the file\n"); 
		exit(0); 
	} 
	
	ca = getc(fa); 
	while(ca!=EOF) 
	{ 
		i=0; 
		buf[i]='\0'; 
		if(ca=='"')
		{
			while(ca!='"')
				ca=getc(fa);
			ca=getc(fa);
		}
		if(isalpha(ca)) 
		{ 
			 while(isalpha(ca)) 
			{ 
				buf[i++]=ca; 
				ca = getc(fa); 
			} 
			buf[i]='\0'; 
			for(int j=0;strcmp(keyw[j],"\0")!=0;j++) 
			{ 
				if(strcmp(buf,keyw[j])==0) 
					printupper(keyw[j]); 
			} 
		} 
		else 
			ca = getc(fa); 
	} 
	fclose(fa); 
	return 0; 
} 