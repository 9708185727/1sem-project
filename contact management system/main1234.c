#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "login.h"
#include "delay.h"
#include "windowscreen.h"
int main()
{
	window();
	if (userExists() == 1)
	{
		printf("User exists\n");
	}
	else
	{

		if (userExists() != 1)
		{
			system("cls"); //clrscr();
			printf("%10s %20s", "", "No user Exist create one.");
			fflush(stdout);
			delay(2);
			showRegisterWindow();
		}
		showLoginWindow();
		if (checkCredential(USER.USERNAME, USER.PASSWORD) == 1)
		{
			printf("\n You are valid user \n");
		}
		else
		{
			printf("\n You are not valid user \n");
		}
	}
	loginAndRedirect();
	return 0;
}
