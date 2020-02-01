#include <stdio.h>
#include <stdlib.h>

void step2(){

    FILE *sfile, *dfile;//Files pointers
    char filename[100], c;
    char ext[10] = ".OUT";//Suffix Var.

    printf("Enter the filename to open for reading \n");
    scanf("%s", filename);

    // Open one file for reading
    sfile = fopen(filename, "r");
    if (sfile == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    strcat(filename, ext); //Adds the suffix ".OUT"

    // Open another file for writing
    //If does not exist, it creates a new one. If exists with
    //the same name, replace the existing file.
    dfile = fopen(filename, "w");
    if (dfile == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    // Read contents from file
    c = fgetc(sfile);
    while (c != EOF)
    {
        fputc(c, dfile);
        c = fgetc(sfile);
    }

    printf("\nContents copied to %s", filename);

    fclose(sfile);
    fclose(dfile);

}
