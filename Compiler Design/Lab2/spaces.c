#include <stdio.h> 
#include <stdlib.h>

int main()
{
    FILE *input, *output;
    char filename[100], c;

    printf("Enter the input filename: ");
    scanf("%s", filename);
    input=fopen(filename, "r");
    //checking filestream integrity
    if(!input){
        printf("File does not exist\n");
        exit(0);
    }
    
    printf("Enter the output filename: ");
    scanf("%s", filename);
    output=fopen(filename, "w+");
    
    c=fgetc(input);
    while(c!=EOF)
    {
        if(c==' ')                                          //checking for successive spaces
        {
            fputc(c, output);
            while(c==' ')
                c=fgetc(input);
        }
        else if(c=='\t')                                    //checking for succesive tab spaces
        {
            fputc(' ', output);                             //replacing with single space
            while(c=='\t')
                c=fgetc(input);
        }
        else
        {
            fputc(c, output);
            c=fgetc(input);
        }
    }
    printf("File '%s' modified successfully!\n", filename);
    fclose(input);
    fclose(output);
    return 0;
}