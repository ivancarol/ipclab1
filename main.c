#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
//Main with a little menu to test all the steps.
int main(){

    int opt;
    printf("Which step do you want to test:\n");
    printf("Options\n");
    printf("1. Step1.c\n");
    printf("2. Step2.c\n");
    printf("3. Step3.c\n");
    printf("4. Step4.c\n");
    printf("5. Step5.c\n");

    do{
    printf("Write the option number:\n");

    scanf("%d", &opt);
    }while(opt!=1 && opt!=2 && opt!=3 && opt!=4 && opt!=5);

    printf("Selected option: %d\n", opt);

    switch(opt){
        case 1:
           step1();
            break;
        case 2:
            step2();
            break;
        case 3:
            step3();
            break;
        case 4:
            step4();
            break;
        case 5:
            step5();
            break;
        default:
            break;
   }
    //step1();*/

    return 0;
}
