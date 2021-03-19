#include <stdio.h>
#include<stdlib.h>

int main()
{
	FILE *fa, *fb;
	int ca, cb;
	char filename[100];
	
	printf("Enter input filename: ");
	scanf("%s", &filename);
	fa = fopen(filename, "r");
	//checking if file is successfully opened
	if (fa == NULL)
	{
		printf("Cannot open file  \n");
		exit(0);
	}
	
	printf("Enter output filename: ");
	scanf("%s", &filename);
	fb = fopen(filename, "w");
	//get first character
	ca = getc(fa);
	//begin comparisons
	while (ca != EOF)
	{
		if(ca==' ')								//checks for blank spaces
		{
			putc(ca,fb);
			while(ca==' ')
				ca = getc(fa);
		}
		if (ca=='/')							//check for beginning of comment
		{
			cb = getc(fa);
			if (cb == '/')						//checks for single line comment
			{
				while(ca != '\n')
					ca = getc(fa);
			}
			else if (cb == '*')					//checks for multiline comment
			{
				do
				{
					while(ca != '*')			//fairly interesting piece of code, checks for random stars in your comments. 
						ca = getc(fa);			//something like this: 4*2=8. This will be ignored and left unedited by the program. 
					ca = getc(fa);
				} while (ca != '/');			//while the comment doesn't end
			}
			else
			{
				putc(ca,fb);
				putc(cb,fb);
			}
		}
		else 
			putc(ca,fb);
		ca = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	printf("\nFile '%s' modified successfully!\n", filename);
	return 0;
}