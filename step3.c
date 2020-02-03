#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_BUFFER 1000

void step3(){

    FILE *sfile, *dfile; //Files pointers
    char filename[100], c;
    char suff[10] = ".OUT"; //Suffix Var.
    char line[SIZE_OF_BUFFER]; //Var. to read lines from source file
    char strToFile[SIZE_OF_BUFFER];//Var. to write lines to destination file

    printf("Enter the filename to open: \n");
    scanf("%s", filename);

    // Opens one file for reading
    sfile = fopen(filename, "r");
    if (sfile == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    strcat(filename, suff); //Adds the suffix ".OUT"

    // Opens another file for writing
    dfile = fopen(filename, "w");

    if (dfile == NULL){
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    // Reads the contents from file

   while(!feof(sfile)){ //While different from EOF...

        fgets (line, SIZE_OF_BUFFER, sfile); //Reads the line from source file

        if(line[strlen(line)-1] == '\n'){ //Checks if the last parameter is a \n
            sprintf(strToFile, "%d",strlen(line)-1);//Substrings 1 to not count the \n.
        }else{
            sprintf(strToFile, "%d",strlen(line));//Prints the int to the string line. The length of the string is the
                                                //number of chars.
        }
        strcat(strToFile," ");
        strcat(strToFile,line); //Adds the number of chars at the beginning of the line
        fputs(strToFile,dfile); //Writes the liens on the destination file
    }

    printf("\nContents copied to %s with the number of chars per line.\n", filename);

    fclose(sfile);
    fclose(dfile);

}
