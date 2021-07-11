#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct LOGINCREDENTIALS
{
	string Username;
	string Password;
};

struct USERDATA
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

	cout << "Data of child: " << endl;
	cout << "Data of parents: " << endl;
	cin >> MainMenuChoice;


	switch (MainMenuChoice)
	{
	case 1:
	{
		cout << "Data of child: " << endl;
		break;
	}
	case 2:
	{
		cout << "Data of parents: " << endl;
		break;
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

void LoginRequest(LOGINCREDENTIALS& LoginCreds)
{
	cout << "Enter Username: " << endl;
	cin >> LoginCreds.Username;
	cout << "Enter Password: " << endl;
	cin >> LoginCreds.Password;
}


void DeleteUser(int& NumberOfLogins, USERDATA UserData[])
{
	int TempId;
	if (NumberOfLogins > 0)
	{
		cout << "All user's Ids:" << endl;
		for (int i = 1; i <= NumberOfLogins; i++)
		{
			cout << UserData[i].Id << endl;
		}
		cout << endl;
		cout << "Enter the Id you want to delete:";
		cin >> TempId;
		bool flag = false;

		for (int i = 1; i <= NumberOfLogins; i++)
		{
			if (TempId == UserData[i].Id)
			{
				UserData[i] = UserData[i + 1];
				flag = true;
			}
			if (flag == true)
			{
				NumberOfLogins--;
				cout << "You have deleted user's info!";
			}
		}
		if (flag != true)
		{
			cout << "You have entered wrong or non-existand id!" << endl;
			cout << "Please enter new id!";
			cout << endl;
			cout << "Enter the id you want to delete:";
			cin >> TempId;
		}
	}
	else
	{
		cout << "There aren't any customers!";
	}
	cout << endl;
}

void ShowUserData(int& NumberOfLogins, USERDATA UserData[])
{
	cout << UserData[NumberOfLogins].Id;
	cout << UserData[NumberOfLogins].FirstName;
	cout << UserData[NumberOfLogins].LastName;
	cout << UserData[NumberOfLogins].Address;
	cout << UserData[NumberOfLogins].ChildName;
	cout << UserData[NumberOfLogins].YearOfChild;
}

int main()
{
	LOGINCREDENTIALS LoginCreds[10];
	USERDATA UsData[10];
	int NumberOfLogins = 1;
}
