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

void InputUserData(int& NumberOfLogins, USERDATA UserData[], LOGINCREDENTIALS LoginCreds[])
{
	cout << "Enter data for the user: " << endl;
	cout << "Enter username: " << endl;
	cin >> LoginCreds[NumberOfLogins].Username;
	cout << "Enter password: " << endl;
	cin >> LoginCreds[NumberOfLogins].Password;
	cout << "Enter id: " << endl;
	cin >> UserData[NumberOfLogins].Id;
	cout << "Enter first name: " << endl;
	cin >> UserData[NumberOfLogins].FirstName;
	cout << "Enter last name: " << endl;
	cin >> UserData[NumberOfLogins].LastName;
	cout << "Enter address: " << endl;
	cin >> UserData[NumberOfLogins].Address;
	cout << "Enter child's name: " << endl;
	cin >> UserData[NumberOfLogins].ChildName;
	cout << "Enter child's age: " << endl;
	cin >> UserData[NumberOfLogins].YearOfChild;
	while (UserData[NumberOfLogins].YearOfChild < 1 || UserData[NumberOfLogins].YearOfChild > 5)
	{
		cout << "Your child's  must be between 1 and 5 years" << endl;
		cout << "Please, enter the child's age again:" << endl;
		cin >> UserData[NumberOfLogins].YearOfChild;
	}
}

void ModifyUser(int& NumberOfLogins, USERDATA UserData[])
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
		cout << "Enter the Id you want to Modify: ";
		cin >> TempId;
		bool flag = false;

		for (int i = 1; i <= NumberOfLogins; i++)
		{
			if (TempId == UserData[i].Id)
			{
				cin >> UserData[i].Id;
				cin >> UserData[i].FirstName;
				cin >> UserData[i].LastName;
				cin >> UserData[i].Address;
				cin >> UserData[i].ChildName;
				cin >> UserData[i].YearOfChild;
				
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

int main()
{
	LOGINCREDENTIALS LoginCreds[10];
	USERDATA UsData[10];
	int NumberOfLogins = 1;
	InputUserData(NumberOfLogins, UsData, LoginCreds);
}
