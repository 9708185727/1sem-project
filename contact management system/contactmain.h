#ifndef contactdetailslogin
#define contactdetailslogin
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include "time.h"
#include "delay.h"
#include<conio.h>//Use for delay(),getch(),gotoxy(),etc.
#include<stdlib.h>
#include<ctype.h>//se for toupper(), tolower(),etc
#include<string.h>//Use for strcmp(),strcpy(),strlen(),etc
#include<ctype.h>

void Add_rec(void);//Add_rec function declaration
void viewlist();//function to list the patient details 
void Search_rec(void);//Search_rec function declaration
void Edit_rec(void);//Edit_rec function declaration
void Dlt_rec(void);//Dlt_rec function declaration
void ex_it(void);//exit function declaration
void headertitle(void);//function for every file of header 

//Defines gotoxy() for ANSI C compilers.
void gotoxy(short x, short y) 
{
COORD pos = {x, y};//sets co-ordinates in (x,y).
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
char ans=0; 
int ok;
int b,num,valid=0;
struct contactdetails//list of global variable
{
	int age;
	char Gender;
	char First_Name[20];
	char Last_Name[20]; 
	char Mobile_no[15];
	
	char Address[30];
	char Email[30];
	char Relationship[20];
	char Notes[20];
};
struct contactdetails  p,temp_c;
//header title
void headertitle()
{
		printf("\n\n\t\t----------------------------------------------------------------------------------");
	printf("\n\t\t\t\t       CONTACT MANAGEMENT SYSTEM        ");
	printf("\n\t\t---------------------------------------------------------------------------");
}


void MainMenu(void)//function decleration
{
	system("cls");
	int choose;
	headertitle();// call Title function
	printf("\n\n\n\n\n\t\t\t\t1. Add Persons Record\n");
	printf("\n\t\t\t\t2. List Persons Record\n");
	printf("\n\t\t\t\t3. Search Persons Record\n");
	printf("\n\t\t\t\t4. Edit Persons Record\n");
	printf("\n\t\t\t\t5. Delete Persons Record\n");
	printf("\n\t\t\t\t6. Exit\n");
	printf("\n\n\n \n\t\t\t\tChoose from 1 to 6:");
	scanf("%i", &choose);
	
	switch(choose)//switch to differeht case
	{
	
        case 1:
	Add_rec();//Add_rec function is called
    	break;
         case 2:
    viewlist();
    	break;
	case 3:
	Search_rec();//View_rec function is call
    	break;
	case 4:
	Edit_rec();//Edit_rec function is call
		break;
	case 5:
	Dlt_rec();//Dlt_rec function is call
		break;
	case 6:
	ex_it();//ex_it function is call
    	break;

	default:
		printf("\t\t\tInvalid entry. Please enter right option :)");
		getch();//holds screen
	}//end of switch
		
	
}
/* ************************************************* Exit Screen ********************************************* */
void ex_it(void)//function to exit
{
	system("cls");
	headertitle();// call Title function
	delay(2);
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
	getch();//holds screen
	
}
/* **************************************ADD RECORD*******************************************/

void Add_rec(void)
{
	system("cls");
	void headertitle(void);//call Title function
	//list of variables
	char ans;
	FILE*ek;//file pointer
	ek=fopen("Record2.dat","a");//open file in write mode
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Add Persons Record !!!!!!!!!!!!!\n");
	
	/* **************************First Name*********************************** */
	
	A:
	printf("\n\t\t\tFirst Name: ");
	scanf("%s",p.First_Name);
	fflush(stdin);
	p.First_Name[0]=toupper(p.First_Name[0]);
	if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
		goto A;
	}
	else
	{
		for (b=0;b<strlen(p.First_Name);b++)
		{
			if (isalpha(p.First_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t First name contain Invalid character :(  Enter again :)");
			goto A;
		}
	}
	
	/* ********************************************** Last name ************************************************ */
	B:
	printf("\n\t\t\tLast Name: ");
    scanf("%s",p.Last_Name);
	fflush(stdin);
    p.Last_Name[0]=toupper(p.Last_Name[0]);
    if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2)
	{
		printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
		goto B;
	}
	else
	{
		for (b=0;b<strlen(p.Last_Name);b++)
		{
			if (isalpha(p.Last_Name[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Last name contain Invalid character :(  Enter again :)");
			goto B;
		}
	}
/* ******************************************* Gender ************************************************************** */	    
	do
	{
	    printf("\n\t\t\tGender[F/M]: ");
		scanf(" %c",&p.Gender);
		fflush(stdin);
		if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
		{
			ok =1;
		}
		else 
		{
		ok =0;
		}
        if(!ok)
	    {
	    	printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
    	}
	 }	while(!ok);
/* ***************************************** Age ********************************************************************** */	
    printf("\n\t\t\tAge:");
    scanf(" %d",&p.age);
	//getinput(p.age);
/* **************************************** Address ******************************************************************* */    
    do
    {
    C:
    printf("\n\t\t\tAddress: ");
    scanf("%s",p.Address);
    fflush(stdin);
    p.Address[0]=toupper(p.Address[0]);
    if(strlen(p.Address)>20||strlen(p.Address)<4)
	{
		printf("\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)");
		goto C;
	}
	
}while(!valid);
/* ******************************************* Mobile no. ***************************************** */
do
{
	D:
    printf("\n\t\t\tMobile no: ");
    scanf("%s",p.Mobile_no);
    if(strlen(p.Mobile_no)>10||strlen(p.Mobile_no)!=10)
	{
		printf("\n\t Sorry :( Invalid. Mobile no. must contain 10 numbers. Enter again :)");
		goto D;
	}
	else
	{
		for (b=0;b<strlen(p.Mobile_no);b++)
		{
			if (!isalpha(p.Mobile_no[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Mobile no. contain Invalid character :(  Enter again :)");
			goto D;
		}
	}
}while(!valid);
/* ************************************************** Email ******************************************** */
do{
	Q:
	printf("\n\t\t\tEmail:");
	scanf("%s",p.Email);
	fflush(stdin);
	if(strstr(p.Email,"@gmail.com")){
		
	}
	else{
		//system("cls");
		printf("\t\t\tInvalid! Please enter again.");
		goto Q;
	}
}while(!valid);

/* ********************************************************* Notes *********************************************** */
    E:
    printf("\n\t\t\tNotes: ");
    scanf("%s",p.Notes);
	fflush(stdin);
    p.Notes[0]=toupper(p.Notes[0]);
    if(strlen(p.Notes)>15||strlen(p.Notes)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 15 and min range is 3 :)");
		goto E;
	}
	else
	{
		for (b=0;b<strlen(p.Notes);b++)
		{
			if (isalpha(p.Notes[b]) || isspace(p.Notes[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Notes contain Invalid character :(  Enter again :)");
			goto E;
		}
	}
/* ********************************************** Any Relationship **************************************** */	
	F:
    printf("\n\t\t\tAny Relationship:");
    scanf("%s",p.Relationship);
	fflush(stdin);
    p.Relationship[0]=toupper(p.Relationship[0]);
    if(strlen(p.Relationship)>30||strlen(p.Relationship)<3)
	{
		printf("\n\t Invalid :( \t The max range for first name is 30 and min range is 3 :)");
		goto F;
	}
	else
	{
		for (b=0;b<strlen(p.Relationship);b++)
		{
			if (isalpha(p.Relationship[b]))
			{
				valid=1;
			}
			else
			{
				valid=0;
				break;
			}
		}
		if(!valid)
		{
			printf("\n\t\t Relationship name contain Invalid character :(  Enter again :)");
			goto F;
		}
	}
    
    fprintf(ek," %s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Mobile_no, p.Email, p.Notes, p.Relationship);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    timer();
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	Add_rec();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\t Thank you :) :)");
    	getch();
    	MainMenu();
	}
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
/* **************************************VIEW RECORD*******************************************/
void viewlist()
{
	int row;
	system("cls");
	void headertitle(void);
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! List Persons Record !!!!!!!!!!!!!\n");
	gotoxy(1,15);
		printf("Full Name");
		gotoxy(24,15);
		printf("Gender");
		gotoxy(32,15);
		printf("Age");
		gotoxy(37,15);
		printf("Address");
		gotoxy(49,15);
		printf("Mobile No.");
		gotoxy(64,15);
		printf("Email");
		gotoxy(86,15);
		printf("Notes");
		gotoxy(98,15);
		printf("\tRelationship\n");
		gotoxy(110,15);
		printf("\t\tTime");
		printf("\n");
		printf("=====================================================================================================================\n");
		row=18;
		while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, 
					&p.Gender, &p.age, p.Address, p.Mobile_no, p.Email, p.Notes, p.Relationship)!=EOF)
		{
			gotoxy(1,row);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(24,row);
			printf("%c",p.Gender);
			gotoxy(32,row);
			printf("%i",p.age);
			gotoxy(37,row);
			printf("%s",p.Address);
			gotoxy(49,row);
			printf("%s",p.Mobile_no);
			gotoxy(64,row);
			printf("%s",p.Email);
			gotoxy(85,row);
			printf("%s",p.Notes);
			gotoxy(105,row);
			printf("%s",p.Relationship);
			gotoxy(110,row);
			printf("\t\t");
			timer();
			printf("\n");
			row++;
		}
		//timer();
		fclose(ek);
		getch();
		system("cls");
		printf("\n\n\n\n\n\t\t\t\t\tThank you\n");
		delay(2);
		MainMenu();
}
void Search_rec(void)

{
	int choose_option;
	char name[20],last[20],Mobile[10];
	system("cls");
	void headertitle(void);//call Title function
	FILE *ek;
	ek=fopen("Record2.dat","r");
	printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Persons Record !!!!!!!!!!!!!\n");
	gotoxy(12,8);
	printf("Please choose any option to search records:\n");
	printf("1.Search by first name.\n");
	printf("2.Search by last name.\n");
	printf("3.Search by Mobile no.\n");
	scanf("%d",&choose_option);
	switch(choose_option){
		case 1:
			printf("Enter the first name:\n");
			scanf("%s",name);
			break;
		case 2:
			printf("Enter the last name:\n");
			scanf("%s",last);
			break;
		case 3:
			printf("Enter the Mobile no:\n");
			scanf("%s",Mobile);
			break;
			default:
			printf("Choose correct option:\n");
			break;
	}
	system("cls");
	fflush(stdin);
	name[0]=toupper(name[0]);
	last[0]=toupper(last[0]);
	Mobile[0]=toupper(Mobile[0]);
	while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Mobile_no, p.Email, p.Notes, p.Relationship)!=EOF)
	{
		if(strcmp(p.First_Name,name)==0 ||strcmp(p.Last_Name,last)==0 ||strcmp(p.Mobile_no,Mobile)==0)
		{
			gotoxy(1,15);
			printf("Full Name");
			gotoxy(25,15);
			printf("Gender");
			gotoxy(32,15);
			printf("Age");
			gotoxy(37,15);
			printf("Address");
			gotoxy(52,15);
			printf("Mobile No.");
			gotoxy(64,15);
			printf("Email");
			gotoxy(86,15);
			printf("Notes");
			gotoxy(98,15);
			printf("\tRelationship\n");
			gotoxy(110,15);
			printf("\t\tTime");
			printf("\n");
			printf("=================================================================================================================\n");
			gotoxy(1,18);
			printf("%s %s",p.First_Name, p.Last_Name);
			gotoxy(25,18);
			printf("%c",p.Gender);
			gotoxy(32,18);
			printf("%i",p.age);
			gotoxy(37,18);
			printf("%s",p.Address);
			gotoxy(52,18);
			printf("%s",p.Mobile_no);
			gotoxy(64,18);
			printf("%s",p.Email);
			gotoxy(85,18);
			printf("%s",p.Notes);
			gotoxy(105,18);
			printf("%s",p.Relationship);
			gotoxy(110,18);
			printf("\t\t");
			timer();
			L:
			getch();
			printf("\n\n\n\n\n\t\t\tDo you want to view more[Y/N]??");
    		scanf("%c",&ans);
    		if (toupper(ans)=='Y')
    		{
        	Search_rec();
    		}
			else if(toupper(ans)=='N')
			{
			printf("\n\t\t Thank you :) :)");
    		getch();
			MainMenu();
    		}
			else
    		{
    		printf("\n\tInvalid Input.\n");
    		goto L;
    		}
    		break;
		}
	}
	//if(strcmp(p.First_Name,name)!=0 || strcmp(p.Last_Name,last)!=0 || strcmp(p.Mobile_no,Mobile)!=0)
	  // {
		gotoxy(5,10);
		printf("Record not found!");
		getch();
		//}
		goto L;
		fclose(ek);
	}

void Edit_rec(void)
{
FILE *ek, *ft;
int i,b, valid=0;
char ch;
int choose_option;
char name[20],last[20],Mobile[10];



system("cls");
void headertitle(void);//call Title window
ft=fopen("temp2.dat","w+");
ek=fopen("Record2.dat","r");
if(ek==NULL)
{
printf("\n\t Can not open file!! ");
getch();
MainMenu();
}
printf("\n\n\t\t\t!!!!!!!!!!!!!! Edit Persons Record !!!!!!!!!!!!!\n");
gotoxy(12,13);
printf("Please choose any option to search records:\n");
printf("1.Search by first name.\n");
printf("2.Search by last name.\n");
printf("3.Search by Mobile no.\n");
scanf("%d",&choose_option);
switch(choose_option){
case 1:
printf("Enter the first name:\n");
scanf("%s",name);
break;
case 2:
printf("Enter the last name:\n");
scanf("%s",last);
break;
case 3:
printf("Enter the Mobile no:\n");
scanf("%s",Mobile);
break;
default:
printf("Choose correct option:\n");
break;
}
system("cls");
fflush(stdin);
name[0]=toupper(name[0]);
last[0]=toupper(last[0]);
Mobile[0]=toupper(Mobile[0]);
gotoxy(12,15);

if(ft==NULL)
{
printf("\n Can not open file");
getch();
MainMenu();
}
while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Mobile_no, p.Email, p.Notes, p.Relationship)!=EOF)
{
if(strcmp(p.First_Name, name)==0 ||strcmp(p.Last_Name,last)==0 ||strcmp(p.Mobile_no,Mobile)==0)
{
valid=1;
gotoxy(25,17);
printf("*** Existing Record ***");
gotoxy(10,19);
printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Mobile_no,p.Email,p.Notes,p.Relationship);
gotoxy(12,22);
printf("Enter New First Name: ");
scanf("%s",p.First_Name);
gotoxy(12,24);
printf("Enter Last Name: ");
scanf("%s",p.Last_Name);
gotoxy(12,26);
printf("Enter Gender: ");
scanf(" %c",&p.Gender);
p.Gender=toupper(p.Gender);
gotoxy(12,28);
printf("Enter age: ");
scanf(" %i",&p.age);
gotoxy(12,30);
printf("Enter Address: ");
scanf("%s",p.Address);
p.Address[0]=toupper(p.Address[0]);
gotoxy(12,32);
printf("Enter Mobile no: ");
scanf("%s",p.Mobile_no);
gotoxy(12,34);
printf("Enter New email: ");
scanf("%s",p.Email);
gotoxy(12,36);
printf("Enter Notes: ");
scanf("%s",p.Notes);
p.Notes[0]=toupper(p.Notes[0]);
gotoxy(12,38);
printf("Enter Relationship: ");
scanf("%s",p.Relationship);
p.Relationship[0]=toupper(p.Relationship[0]);
printf("\nPress U charecter for the Updating operation : ");
ch=getche();
if(ch=='u' || ch=='U')
{
fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Mobile_no,p.Email,p.Notes,p.Relationship);
printf("\n\n\t\t\t contact record updated successfully...");
timer();
}
}
else
{
fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Mobile_no,p.Email,p.Notes,p.Relationship);
}
}
if(!valid) printf("\n\t\tNO RECORD FOUND...");
fclose(ft);
fclose(ek);
remove("Record2.dat");
rename("temp2.dat","Record2.dat");
getch();
MainMenu();
}
void Dlt_rec()
{
char name[20];
int found=0;
system("cls");
void headertitle(void);//call Title function
FILE *ek, *ft;
ft=fopen("temp_file2.dat","w+");
ek=fopen("Record2.dat","r");
printf("\n\n\t\t\t!!!!!!!!!!!!!! Delete Persons Record !!!!!!!!!!!!!\n");
gotoxy(12,8);
printf("\n Enter Person Name to delete: ");
fflush(stdin);
gets(name);
name[0]=toupper(name[0]);

while (fscanf(ek,"%s %s %c %i %s %s %s %s %s", p.First_Name, p.Last_Name, &p.Gender,
&p.age, p.Address, p.Mobile_no, p.Email, p.Notes, p.Relationship)!=EOF)
{
if (strcmp(p.First_Name,name)!=0)
fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Mobile_no, p.Email, p.Notes, p.Relationship);
else
{
printf("%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Mobile_no, p.Email, p.Notes, p.Relationship);
found=1;
}
}//while loop ends
if(found==0)
{
printf("\n\n\t\t\t Record not found....");
getch();
MainMenu();
}
else
{
fclose(ek);
fclose(ft);
remove("Record2.dat");
rename("temp_file2.dat","Record2.dat");
printf("\n\n\t\t\t Record deleted successfully :) ");
getch();
MainMenu();
}
}
#endif

