#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *input,*output;
    char filename[100], ca, cb;
    
    printf("\nEnter input filename:");
    scanf("%s",filename);
    input=fopen(filename,"r");
    //checking filestream integrity
    if(!input){
        printf("File does not exist\n");
        exit(0);
    }

    printf("\nEnter the output filename: ");
    scanf("%s", filename);
    output=fopen(filename, "w+");
   
    ca=fgetc(input);
    while(ca!=EOF)
    {
        if(ca=='"')                                          //gnoring strings
        {
            fputc(ca,output);
            ca=fgetc(input);
            fputc(ca,output);
            while(ca!='"')
            {
                if(ca=='\\')                                //dealing with cases such as \"" in the string.
                {                                           //Sice the string doesn't end in this "" the following ppd mustn't be deleted
                    ca=fgetc(input);
                    fputc(ca,output);
                }
                ca=fgetc(input);
                fputc(ca,output);
            }
        }
        else if(ca=='\'')                                   //Dealing with single quote cases
        {
            fputc(ca,output);
            ca=fgetc(input);
            fputc(ca,output);
            while(ca!='\'')
            {
                ca=fgetc(input);
                fputc(ca,output);
            }
        }
        else if(ca=='#')
        {
            while(ca!='\n') 
                ca=fgetc(input);
        }
        else  
            fputc(ca,output);
        ca=fgetc(input);
    }
    fclose(input);
    fclose(output);
    printf("File '%s' modified successfully!\n", filename);
    return 0;
}