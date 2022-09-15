#include "App.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int k = 0;
int i = 0;
struct Account account[50];
int l = 0;


void  ID(void) {
	int Size = 0;
	unsigned long long int ID;
	printf("Enter your ID:");
	scanf(" %llu",&ID);
	account[i].ID = ID;
	do 
	{
		ID /= 10;
		Size++;
	}while (ID != 0);


	if (Size != 14) 
	{
		printf("Invalid \n");
	}
}

void  Password(void)
{
	char paassword[20]="";
	printf("Enter your Password:");
	
	scanf(" %s", &paassword);
	strcpy(account[i].Password, paassword);
	
}

void  Age(void)
{
	int Age;
	printf("Enter your Age:");
	scanf(" %d", &Age);
	account[i].Age = Age;

	if (account[i].Age < 21) {
		printf("Invalid \n");
	}
}

void  Balance(void)
{
	double Balance;
	printf("Enter your balance:");
	scanf(" %lf", &Balance);
	account[i].Balance = Balance;
	if (account[i].Balance < 0) {
		printf("Invalid \n");
	}
}



void  Fullname(void)
{
	char FullName[21];
	int Size;
	printf("Enter Your Fullname At Least Four Names:");
	
	scanf(" %[^\n]",&FullName);

	Size = strlen(FullName);

	if (Size > 21) {
		printf("Invalid \n");
	}
	else
	{
		strcpy(account[i].UserName, Fullname);
	}

}

void  Fulladress()
{
	char FullAddress[21] ;
	printf("Enter Your FullAddress:");
	
	scanf(" %[^\n]", &FullAddress);

	printf("\n");
	
	strcpy(account[i].FullAdress, Fulladress);
}



void  plus()
{
	k = ++i;
}

void  checkforadmin()
{
	int Choice;

	do {
		printf("Press 1 To Make Transaction \nPress 2 To Change Account Status \nPress 3 To Get Cash \nPress 4 To Deposit in Account \nPress 5 To Return To Main Menu:");

		scanf("%d", &Choice);

		if (Choice == 1) {
			transaction();
		}

		else if (Choice == 2) {
			changeaccountstatus();
		}

		else if (Choice == 3) {
			getcash();
		}

		else if (Choice == 4) {
			addcash();
		}

		else if (Choice == 5) {
			printf("You Return To Main Menu \n\n");
		}

		else {
			printf("Invalid \n");
		}

	} while (Choice <= 4);
}

void  checkforclient()
{
	int Choice;

	do {
		printf("Press 1 To Make Transaction \nPress 2 To Change Account Password \nPress 3 To Get Cash\nPress 4 To Deposit in Account \nPress 5 To Return To Main Menu:");
		scanf("%d", &Choice);

		if (Choice == 1) {
			transaction();
		}

		else if (Choice == 2) {
			changeaccountpassword();
		}

		else if (Choice == 3) {
			getcash();
		}

		else if (Choice == 4) {
			addcash();
		}

		else if (Choice == 5) {
			printf("You Return To Main Menu \n");
		}

		else {
			printf("Invalid \n");
		}

	} while (Choice <= 4);
}

void  transaction()
{
	unsigned long long int ID;
	int Index = 0;
	double Balance;
	printf("Enter Clint ID To Transfer Money:");

	scanf("%llu", &ID);
	printf("\n");

	for (int i = 0; i < k; i++) {

		if (account[i].ID == ID) {

			Index = i;

			if (account[l].Status == account[Index].Status) {
				printf("Enter The Money To Transfer It:");

				scanf("%lf", &Balance);
				printf("\n");

				if (Balance > account[l].Balance) {
					printf("Invalid \n");
				}

				account[Index].Balance = account[Index].Balance + Balance;
				account[l].Balance = account[l].Balance - Balance;
				printf("Now Your Money In Your Account Become: %lf ", account[l].Balance);

			}

			else {
				printf("Invalid \n");
			}

		}

	}

	if (Index == 0) {
		printf("Invalid \n");
	}
}

void  changeaccountstatus()
{
	int Status;
	printf("Press 1 To Change Statue To Active \nPress 2 To Change Statue To  Restricted \nPress 3 To Change Statue To  Closed:");
	
	scanf("%d", &Status);

	if (Status == 1) {
		account[l].Status = "active";
		printf("it is now %s \n", account[l].Status);
	}

	else if (Status == 2) {
		account[l].Status = "Restricted";
		printf("it is now %s \n", account[l].Status);
	}

	else if (Status == 3) {
		account[l].Status = "Closed";
		printf("it is now %s \n", account[l].Status);
	}

	else {
		printf("Invalid \n");
	}
}

void  getcash()
{
	double Balance;
	printf("Enter The Money You Want From This Account:");

	scanf("%lf", &Balance);
	printf("\n");
	if (Balance > account[l].Balance) {
		printf("Invalid \n");
	}

	else {
		account[l].Balance = account[l].Balance - Balance;
		printf("You Got %lf From Your Account \nNow Your Money In Your Account Become: %lf \n", Balance, account[l].Balance);

	}
}

void  addcash()
{
	double Balance;
	printf("Enter The Money That You Add To This Account:  ");

	scanf("%lf",&Balance);
	printf("\n");
	if (Balance < 0) {
		printf("Invalid \n");
	}

	else {
		account[l].Balance = account[l].Balance + Balance;
		printf("You Added %lf To Your Account %s \nNow Your Money In Your Account Become: %lf\n", Balance, account[l].UserName, account[l].Balance);
	}
}

void  changeaccountpassword()
{
	char Oldpassword[21] = "";
	char Newpassword[21] = "";
	int flag = 0;
	printf("Enter Clint Old Password:");

	scanf("%s",&Oldpassword);

	for (int i = 0; i < k; i++) {

		if (strcmp(account[i].Password,Oldpassword)==0) {

			l = i;
			flag = 1;
			printf("Enter Clint New Password:");

			scanf("%s",&Newpassword);
			printf("\n");
			strcpy(account[i].Password, Newpassword);

		}

	}

	if (flag == 0) {
		printf("Invalid \n");
	}
}

void  openaccount(int Switch)
{

	unsigned long long int ID;
	int flag = 0;
	char Password[21] = "";

	printf("Enter Clint ID:");

	scanf("%llu", &ID);
	printf("\n");

	if (Switch == 1) {

		for (int i = 0; i < k; i++) {

			if (account[i].ID == ID) {
				l = i;
				flag = 1;
				checkforadmin();
			}

		}
	}

	else if (Switch == 2) {
		printf("Enter Clint Password:");

		scanf("%s",&Password);
		printf("\n");
	
		
		for (int i = 0; i < k; i++) 
		{
			
			if (account[i].ID == ID && (strcmp(account[i].Password, Password) == 0))
			{
				l = i;
				flag = 1;
				checkforclient();
			}

		}

	}

	if (flag == 0) {
		printf("Invalid \n");
	}
}

void Makeaccount() 
{
	 Fullname();
	 fflush(stdin);
	 Fulladress();
	 fflush(stdin);
	 ID();
	 fflush(stdin);
	 Password();
	 Age();
	 Balance();
	 plus();
}
void openaccountforadminandclient(int Switch) {
	openaccount(Switch);
}

void AppStart()
{
	int Choice, flag = 0, Switch, Answer;

	do {
		
		printf("Hi,This Application For The Bank \n");

		printf("\nPress 1 For Admin Account \nPress 2 For Client Account:");

		scanf("%d", &Switch);

		if (Switch == 1) {
			printf("\nPress 1 Create Account Number 1 \nPress 2 Open Existing Account Number 2 \nPress 3 Exit System Number 3: ");
			
			scanf(" %d", &Choice);

			if (Choice == 1) {
				Makeaccount();
				flag = 1;
			}

			else if (Choice == 2 && flag == 1) {
				openaccountforadminandclient(Switch);
			}

			else if (Choice == 3) {
				system("CLS");
				return;
			}

			else {
				printf("Invalid \n");
			}


		}

		else if (Switch == 2) {
			openaccountforadminandclient(Switch);
		}

		else {
			printf("Invalid \n");
		}


	} while (Switch < 3);
}