#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE_OF_BUFFER 1000

void step4()
{

    FILE *sfile,*dfile;
    char filename[100];
    char line[SIZE_OF_BUFFER]; //Var. to read lines from source file
    char suff[10] = ".OUT"; //Suffix Var.

    printf("Enter the filename to open \n"); //Asks for the file name
    scanf("%s", filename); //Reads from keyboard

    sfile = fopen(filename, "r");
    if (sfile == NULL) //Checks if the return is null
    {
        printf("Cannot open file \n"); //If null, is not possible open the file
        exit(0); //end of program
    }
    strcat(filename, suff); //Adds the suffix ".OUT"

    // Open another file for writing
    dfile = fopen(filename, "w");
    if (dfile == NULL)
    {
        printf("Cannot open file %s \n", filename);
        exit(0);
    }

    while(!feof(sfile))  //While different from EOF...
    {

        fgets (line, SIZE_OF_BUFFER, sfile); //Reads the line from source file
        //printf("%s",line);
        push(line);
        printf("Element at top of the stack: %s\n" ,peek());
       // printf("%s",line);
    }

    while(!isempty()) {
      int data = pop();
      printf("%s\n",data);
   }


//    rev_file_line(sfile);
    fclose(sfile);
    fclose(dfile);

}


void reverse(char buf)
{
    //static char buf[10000];
    if (fgets(buf, sizeof(buf), stdin))
    {
        char *str = strdup(buf);
        reverse(buf);
        fputs(str, stdout);
        free(str);
    }
}



int MAXSIZE = 1000;
int stack[1000];
int top = -1;

int isempty()
{

    if(top == -1)
        return 1;
    else
        return 0;
}

int isfull()
{

    if(top == MAXSIZE)
        return 1;
    else
        return 0;
}

int peek()
{
    return stack[top];
}

int pop()
{
    int data;

    if(!isempty())
    {
        data = stack[top];
        top = top - 1;
        return data;
    }
    else
    {
        printf("Could not retrieve data, Stack is empty.\n");
    }
}

int push(int data)
{

    if(!isfull())
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Could not insert data, Stack is full.\n");
    }
}
/*
void rev_file_line(FILE *fp){
    char buf[MAX_LINE_SIZE];
    char *s;
    s=fgets(buf,sizeof buf,fp);
    if(NULL==s)
    {
        if(ferror(fp))
        {
            perror(NULL);
            exit(EXIT_FAILURE);
        }
        else
            return;
    }
    rev_file_line(fp);
    fputs(buf,stdout);
}*/
