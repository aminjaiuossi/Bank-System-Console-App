#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

class clsDepositScreen : protected clsScreen
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

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t  Depsit Screen");
		string AccountNumber = _ReadAccountNumber();
		
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client with [" << AccountNumber <<"] does not exist ,Enter another one : ";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		cout << "\nPlease enter an deposit amount : ";
		double Amount = clsInputValidate::ReadDblNumber();

		cout << "Are you sure you want to perform the deposit ? Y/N ? \n";
		char Answer;
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			Client.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is: " << Client.AccountBalance;
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}
};

