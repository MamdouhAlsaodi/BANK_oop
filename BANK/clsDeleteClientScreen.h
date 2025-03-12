#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsScreen.h"
class clsDeleteClientScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.FirstName;
        cout << "\nLastName    : " << client.LastName;
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nEmail       : " << client.Email;
        cout << "\nPhone       : " << client.Phone;
        cout << "\nAcc. Number : " << client.AccountNumber();
        cout << "\nPassword    : " << client.PinCode;
        cout << "\nBalance     : " << client.AccountBalance;
        cout << "\n___________________\n";
    }
public:
    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t  Delete cleints";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Not Find ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient cleint1 = clsBankClient::Find(AccountNumber);
        _PrintClient(cleint1);

        cout << "\nAre you shour deleit: y/n\t";
        char  Anser = 'n';
        cin >> Anser;

        if (Anser == 'y' || Anser == 'Y')
        {
            if (cleint1.Delete())
            {
                cout << "\nClein Delet Ssufly\n";
                _PrintClient(cleint1);
            }
            else
            {
                cout << "\n Erro not Client Deleat\n";
            }
        }
    }
};

