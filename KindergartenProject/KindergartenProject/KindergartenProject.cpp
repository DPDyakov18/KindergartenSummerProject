#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct LOGINCREDENTIALS
{
	string Username;
	string Password;
};

struct DATA
{
	int Id;
	string FirstName;
	string LastName;
	string Address;
	string ChildName;
	int YearOfChild;
};

void AdminMenu()
{
	int AdminMenuChoice;
	cin >> AdminMenuChoice;

	switch (AdminMenuChoice)
	{
	case 1:
	{
		cout << "Create" << endl;
	}
	case 2:
	{
		cout << "Register" << endl;
	}
	case 3:
	{
		cout << "Delete" << endl;
	}
	case 4:
	{
		cout << "Modify" << endl;
	}
	}
}
void MainMenu()
{
	int MainMenuChoice;
	cin >> MainMenuChoice;

	switch (MainMenuChoice)
	{
	case 1:
	{
		cout << "View data of child: " << endl;
	}
	case 2:
	{
		cout << "View data of parents: " << endl;
	}
	}
}

bool CheckIfAdmin(LOGINCREDENTIALS &LoginCreds)
{
	if (LoginCreds.Username == "a" && LoginCreds.Password == "a")
	{
		return true;
	}
	return false;
}

void LoginRequest(LOGINCREDENTIALS &LoginCreds)
{
	cout << "Input username:"<<endl;
	cin >> LoginCreds.Username;
	cout << "Input password:" << endl;
	cin >> LoginCreds.Password;
}

int main()
{	
	LOGINCREDENTIALS LoginCreds[100];
	int NumberOfLogins=0;
	LoginRequest(LoginCreds[NumberOfLogins]);
	cout << CheckIfAdmin(LoginCreds[NumberOfLogins]);
	NumberOfLogins++;
}