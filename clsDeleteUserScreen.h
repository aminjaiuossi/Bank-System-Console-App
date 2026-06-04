#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;

class clsDeleteUserScreen : protected clsScreen
{
private:
	static void _PrintUser(clsUser& User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";
	}

public:
	static void ShowDeleteUserScreen()
	{
		cout << "Enter UserName to delete : \n";
		string UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUserName Was Not Found , Please Enter Another One : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		_PrintUser(User);

		cout << "Are you sure you want to delete this user ? Y/N ? \n";
		char Answer;
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			if (User.Delete())
			{
				cout << "User deleted successfully :) ";
				_PrintUser(User);
			}
			else
			{
			cout << "\nError ,Client Was not Deleted\n";
			}
		}
		

	}
};

