#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_OF_BUFFER 1000

int main(){

    FILE *sfile,*dfile; ////Files pointers
    char filename[100],c;
    char line[SIZE_OF_BUFFER]; //Var. to read lines from source file
    char suff[10] = ".OUT"; //Suffix Var.
    int lineCount=0;//Var. to save the number of lines
    int charCount=0;//Var. to save the number of chars in a line
    char table[SIZE_OF_BUFFER][SIZE_OF_BUFFER]; //table to save the lines with his chars


    printf("Enter the filename to open \n"); //Asks for the file name
    scanf("%s", filename); //Reads from keyboard

    sfile = fopen(filename, "r");
    if (sfile == NULL) //Checks if the return is null
    {
        printf("Cannot open file \n"); //If null, is not possible open the file
        exit(0); //end of program
    }
    strcat(filename, suff); //Adds the suffix ".OUT"

    // Opens another file for writing
    dfile = fopen(filename, "w");
    if (dfile == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }


    // Reads the contents from file

    c = fgetc(sfile); //gets the char from the pointer
                    //fgetc returns EOF if is the end of the file

    while (c != EOF) //If it's different from End Of File...
    {
        table[lineCount][charCount]=c; //Saves the char in the right position of the table
        charCount++;
        if(c=='\n'){    //If it is a \n...
            lineCount++;
            charCount=0;
        }
        c = fgetc(sfile); //reads another char

    }

    table[lineCount][charCount]='\0'; //Adds a identifier to know the end of the last line.

    for(int i=lineCount; i>=0; i--){ //For each line saved...
        int j=0;
        while(table[i][j]!= '\n' && table[i][j]!= '\0') //If it is different from a \n or the "last line" mark...
        {
            fputc(table[i][j], dfile);  //saves each char of the line in the destination file
            j++;

        }
        fputc('\n', dfile); //Adds the remaining \n
    }
    printf("\nContents copied to %s.\n", filename);

    fclose(sfile);
    fclose(dfile);
	
	return 0;

}
