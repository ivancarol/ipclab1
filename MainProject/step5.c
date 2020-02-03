#include <stdio.h>
#include <string.h>
#include <string.h>

void step5(){

    FILE *sfile, *dfile; //Files pointers
    int numChars = 0; //number of total chars in the file
    int i   = 0;
    char filename[100], c;
    char suff[10] = ".OUT"; //Suffix Var.

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


    fseek(sfile,0,SEEK_END); //moves the file pointer to the end of the file

    numChars = ftell(sfile);//gets the size (chars) of the file


    while( i < numChars ){  //While does not iterates all the file...

        i++;
        fseek(sfile,-i,SEEK_END); //sets the cursor to the "i" position (offset).
                                    //begins at the end and goes backwards
        fputc(fgetc(sfile),dfile); //writes the char in the dfile

    }

    fclose(sfile);
    fclose(dfile);
}
