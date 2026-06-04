#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

using namespace std;
class clsDeleteClientScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}
public:
	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		cout << "Enter Account number to delete : \n";
		string AccountNumber = clsInputValidate::ReadString();
		
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Was Not Found , Please Enter Another One : ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		char Answer = 'n';
		cout << "Are you sure you want to delete this client ? Y/N ? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			if (Client.Delete())
			{
				cout << "Client Deleted Successfully :)\n";
				_PrintClient(Client);
			}
			else
			{
				cout << "\nError ,Client Was not Deleted\n";
			}
		}

	}
};