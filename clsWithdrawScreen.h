#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
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

	static string _ReadAccountNumber()
	{
		cout << "Enter Account Number : \n";
		string AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;
	}

public:

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t  Depsit Screen");
		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client with [" << AccountNumber << "] does not exist ,Enter another one : ";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nPlease enter an withdraw amount : ";
		double Amount = clsInputValidate::ReadDblNumber();

		cout << "Are you sure you want to perform the withdarw ? Y/N ? \n";
		char Answer;
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\nAmount Withdarwed Successfully.\n";
				cout << "\nNew Balance Is: " << Client.AccountBalance;
			}
			else
			{
				cout << "\nCannot Withdraw ,Insuffecient balance :<";
				cout << "\nAmount to withdraw is : " << Amount;
				cout << "\nAccount Balance is : " << Client.AccountBalance << endl;
			}
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}
};

