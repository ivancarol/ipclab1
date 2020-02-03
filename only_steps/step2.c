#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *sfile, *dfile;//Files pointers
    char filename[100], c;
    char ext[10] = ".OUT";//Suffix Var.

    printf("Enter the filename to open for reading \n");
    scanf("%s", filename);

    //Opens one file for reading
    sfile = fopen(filename, "r");
    if (sfile == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    strcat(filename, ext); //Adds the suffix ".OUT"

    //Opens another file for writing
    //If it does not exist, it creates a new one. If it exists with
    //the same name, replace the existing file.
    dfile = fopen(filename, "w");
    if (dfile == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    // Reads contents from file
    c = fgetc(sfile);
    while (c != EOF)
    {
        fputc(c, dfile);
        c = fgetc(sfile);
    }

    printf("\nContents copied to %s", filename);

    fclose(sfile); //closing of the files channels
    fclose(dfile);
	
	return 0;
}
