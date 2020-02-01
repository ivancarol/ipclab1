#include <stdio.h>
#include <stdlib.h>
void step1(){

  FILE *file; //Declaration of a Pointer

    char filename[100], c; //Declaration of variables

    printf("Enter the filename to open \n"); //Asks for the file name
    scanf("%s", filename); //Reads from keyboard

    // Open file

    file = fopen(filename, "r"); //Opens the file in read mode
    if (file == NULL) //Checks if the return is null
    {
        printf("Cannot open file \n"); //If null, is not possible open the file
        exit(0); //end of program
    }

    // Read contents from file
    c = fgetc(file); //gets the char from the pointer
                    //fgetc returns EOF if is the end of the file
    while (c != EOF) //If it's different from End Of File...
    {
        printf ("%c", c); //prints the char
        c = fgetc(file); //and reads another char
    }

    fclose(file);//End of file, It close the channel.
}
