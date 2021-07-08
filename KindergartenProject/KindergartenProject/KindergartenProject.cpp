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