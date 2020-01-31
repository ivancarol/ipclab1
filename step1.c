#include <stdio.h>
#include <stdlib.h>
void step1(){

  FILE *fptr; //Declaration of a Pointer

    char filename[100], c; //Declaration of variables

    printf("Enter the filename to open \n"); //Asks for the file name
    scanf("%s", filename); //Reads from keyboard

    // Open file

    fptr = fopen(filename, "r"); //Opens the file in read mode
    if (fptr == NULL) //Checks if the return is null
    {
        printf("Cannot open file \n"); //If null, is not possible open the file
        exit(0); //end of program
    }

    // Read contents from file
    c = fgetc(fptr); //gets the char from the pointer
                    //fgetc returns EOF if is the end of the file
    while (c != EOF) //If it's different from End Of File...
    {
        printf ("%c", c); //prints the char
        c = fgetc(fptr); //and reads another char
    }

    fclose(fptr);//End of file, It close the channel.
}
