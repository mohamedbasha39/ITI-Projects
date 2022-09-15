#pragma once


struct Account {

	char UserName[21];
	char FullAdress[21];
	char Password[21];
	const char* Status;
	int Age;
	unsigned long long int ID;
	double Balance;

};

void getfullname(char* Fullname, int Size);

void getfulladress(char* Fulladress);

void ID(void);


void Password(void);

void Age(int Age);

void Balance(void);

void Increase();


void Fullname();

void Fulladress();

void ID();

void Password();
void Age();

void Balance();

void plus();







void checkforadmin();

void checkforclient();

void transaction();


void changeaccountstatus();


void getcash();


void addcash();


void changeaccountpassword();

void openaccount(int Switch);



void Makeaccount();
void openaccountforadminandclient(int Switch);
void AppStart();



	




