#include <iostream>
#include <string>
#include <string.h>
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


bool CheckIfAdmin(int& NumberOfLogins, LOGINCREDENTIALS LoginCreds[])
{
	if (LoginCreds[NumberOfLogins].Username == "a" && LoginCreds[NumberOfLogins].Password == "a")
	{
		return true;
	}
	return false;
}


void LoginRequest(int& NumberOfLogins, LOGINCREDENTIALS LoginCreds[])
{
	cout << "Enter Username: " << endl;
	cin >> LoginCreds[NumberOfLogins].Username;
	cout << "Enter Password: " << endl;
	cin >> LoginCreds[NumberOfLogins].Password;
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

void CreateUser(int& NumberOfLogins, USERDATA UserData[], LOGINCREDENTIALS LoginCreds[])
{
	cout << "Enter data for the user: " << endl;
	cout << "Enter username: " << endl;
	cin >> LoginCreds[NumberOfLogins].Username;
	cout << "Enter password: " << endl;
	cin >> LoginCreds[NumberOfLogins].Password;
	do
	{
		cout << "Enter id: " << endl;
		cin >> UserData[NumberOfLogins].Id;
	} while (UserData[NumberOfLogins].Id < 0);
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
				cout << "Enter id:" << endl;
				cin >> UserData[i].Id;
				cout << "Enter first name" << endl;
				cin >> UserData[i].FirstName;
				cout << "Enter last name" << endl;
				cin >> UserData[i].LastName;
				cout << "Enter address" << endl;
				cin >> UserData[i].Address;
				cout << "Enter child name" << endl;
				cin >> UserData[i].ChildName;
				cout << "Enter age of a child" << endl;
				cin >> UserData[i].YearOfChild;
				flag = true;
				
			}
			if (flag == true)
			{
				cout << "You have modified user's info!";
			}
		}
		
		if (flag != true)
		{
			cout << "You have entered wrong or non-existand id!" << endl;
			cout << "Please enter new id!";
			cout << endl;
			cout << "Enter the id you want to modify:";
			cin >> TempId;
		}
	}
	else
	{
		cout << "There aren't any users!";
	}
	cout << endl;

}

void ShowUserData(int& NumberOfLogins, USERDATA UserData[])
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
		cout << "Enter the Id you want to see the data of ";
		cin >> TempId;
		bool flag = false;

		for (int i = 1; i <= NumberOfLogins; i++)
		{
			if (TempId == UserData[i].Id)
			{
				cout << "First name: " << UserData[i].FirstName << endl;
				cout << "Last name: " << UserData[i].LastName << endl;
				cout << "Address: " << UserData[i].Address << endl;
				cout << "Child's name: " << UserData[i].ChildName << endl;
				cout << "Child's age: " << UserData[i].YearOfChild << endl;
				flag = true;
			}
		}
		if (flag != true)
		{
			cout << "You have entered wrong or non-existand id!" << endl;
			cout << "Please enter new id!";
			cout << endl;
			cout << "Enter the id you want to see the user's data:";
			cin >> TempId;
		}
	}
	else
	{
		cout << "There aren't any users!";
	}
	cout << endl;

}

void ShowChildData(int& NumberOfLogins, USERDATA UserData[])
{
	string TempLastName;
	if (NumberOfLogins > 0)
	{
		cout << "All user's last names:" << endl;
		for (int i = 1; i <= NumberOfLogins; i++)
		{
			cout << UserData[i].LastName << endl;
		}
		cout << endl;
		cout << "Enter the last name of a parent to select the child you want to see the data of ";
		cin >> TempLastName;
		bool flag = false;

		for (int i = 1; i <= NumberOfLogins; i++)
		{
			if (TempLastName==UserData[i].LastName)
			{
				cout << "Child's name: " << UserData[i].ChildName << endl;
				cout << "Child's age: " << UserData[i].YearOfChild << endl;
				flag = true;
			}
		}
		if (flag != true)
		{
			cout << "You have entered wrong or non-existand last name!" << endl;
			cout << "Please enter new last name!";
			cout << endl;
			cout << "Enter the last name you want to see the child's data of:";
			cin >> TempLastName;
		}
	}
	else
	{
		cout << "There aren't any users!";
	}
	cout << endl;
}

void ShowParentData(int& NumberOfLogins, USERDATA UserData[])
{
	string TempChildName;
	if (NumberOfLogins > 0)
	{
		cout << "All user's Ids:" << endl;
		for (int i = 1; i <= NumberOfLogins; i++)
		{
			cout << UserData[i].LastName << endl;
		}
		cout << endl;
		cout << "Enter the child's name to select the parent you want to see the data of ";
		cin >> TempChildName;
		bool flag = false;

		for (int i = 1; i <= NumberOfLogins; i++)
		{
			if (TempChildName == UserData[i].ChildName)
			{
				cout << "Parent's first name: " << UserData[i].FirstName << endl;
				cout << "Parent's last age: " << UserData[i].LastName << endl;
				flag = true;
			}
		}
		if (flag != true)
		{
			cout << "You have entered wrong or non-existand child name!" << endl;
			cout << "Please enter new name!";
			cout << endl;
			cout << "Enter the id you want to see the parent's data:";
			cin >> TempChildName;
		}
	}
	else
	{
		cout << "There aren't any users!";
	}
	cout << endl;
}

int MainMenu(int& NumberOfLogins, USERDATA UserData[], LOGINCREDENTIALS LoginCreds[], bool flag)
{
	int MainMenuChoice;
	do
	{
		cout << "1. Show user data: " << endl;
		cout << "2. Show child data: " << endl;
		cout << "3. Show parent data: " << endl;
		cout << "4. Exit" << endl;
		cin >> MainMenuChoice;
		switch (MainMenuChoice)
		{
		case 1:
		{
			ShowUserData(NumberOfLogins, UserData);
			break;
		}
		case 2:
		{
			ShowChildData(NumberOfLogins, UserData);
			break;
		}
		case 3:
		{
			ShowParentData(NumberOfLogins, UserData);
			break;
		}
		case 4:
		{
			cout << "Thank you for using the program!";
			return flag = 0;
			break;
		}
		default:
		{
			cout << "Incorrect input!" << endl;
			cout << "Please, select a menu again!" << endl;
		}
		}
	} while (flag == 1);
}

int AdminMenu(int& NumberOfLogins, USERDATA UserData[], LOGINCREDENTIALS LoginCreds[], bool flag)
{
	int AdminMenuChoice;
	do
	{
		cout << "1. Create user: " << endl;
		cout << "2. Delete user: " << endl;
		cout << "3. Modify user: " << endl;
		cout << "4. Show all data of users:" << endl;
		cout << "5. Show a child's data:" << endl;
		cout << "6. Show data of a parent:" << endl;
		cout << "7. Login:" << endl;
		cout << "8. Exit program" << endl;
		cin >> AdminMenuChoice;
		switch (AdminMenuChoice)
		{
		case 1:
		{
			CreateUser(NumberOfLogins, UserData, LoginCreds);
			break;
		}
		case 2:
		{
			DeleteUser(NumberOfLogins, UserData);
			break;
		}
		case 3:
		{
			ModifyUser(NumberOfLogins, UserData);
			break;
		}
		case 4:
		{
			ShowUserData(NumberOfLogins, UserData);
			break;
		}
		case 5:
		{
			ShowChildData(NumberOfLogins, UserData);
			break;
		}
		case 6:
		{
			ShowParentData(NumberOfLogins, UserData);
			break;
		}
		case 7:
		{
			LoginRequest(NumberOfLogins, LoginCreds);
			if (CheckIfAdmin(NumberOfLogins, LoginCreds) == 1)
			{
				AdminMenu(NumberOfLogins, UserData, LoginCreds, flag);
				AdminMenuChoice = 8;
			}
			else
			{
				MainMenu(NumberOfLogins, UserData, LoginCreds, flag);
				AdminMenuChoice = 8;
			}
		}
		case 8:
		{
			cout << "Thank you for using the program!";
			return flag = 0;
			break;
		}
		default:
		{
			cout << "Incorrect input!" << endl;
			cout << "Please, select a menu again!" << endl;
		}
		}
	} while (flag == 1);

}

int main()
{
	LOGINCREDENTIALS LoginCreds[10];
	USERDATA UsData[10];
	int NumberOfLogins = 1;
	bool flag = 1;
	LoginRequest(NumberOfLogins, LoginCreds);
	if(CheckIfAdmin(NumberOfLogins, LoginCreds) == 1)
	{
		AdminMenu(NumberOfLogins, UsData, LoginCreds,flag);
	}
	else
	{
		MainMenu(NumberOfLogins, UsData, LoginCreds,flag);
	}
}
