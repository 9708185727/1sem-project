#ifndef welcome
#define welcome
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void window();//declearation of function for showing window screen for contact management system
/* *********************************************** Welcome Screen ******************************************* */
void window() //showing login
{
    
    printf("\n\n\n\n\n\n\n\t\t\t\t#########################################\n");
    printf("\n\t\t\t\t\t\t WELCOME TO\t\t");
    printf("\n\t\t\t\t        CONTACT MANAGEMENT SYSTEM   \t\n");
    printf("\n\t\t\t\t#########################################");
    printf("\n\n");
    printf("\t\t\t\t\t       Project-I   ");
    printf("\n\t\t\t\t\t## BIT 1st Semester ##\n");
    printf("\t\t\t\t\t  ## CITE College ##\n");
    printf("\t\t\t\t\t   ## 2020 Batch ##\n");
    printf("\n");
    printf("\tPrepared By:\n");
	printf("\t\tSujan Thapa\n\t\tRaman Chaudhary\n\t\tAlok Poddar Baishya\n\t\tAnish Chaudhary\n");
    printf("\n\n Press any key to continue......\n");
    
    getch();
    system("cls");//Use to clear screen
    
}
#endif

