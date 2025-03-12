#pragma once
#include <iostream>
#include "Global.h"
#include "clsUser.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
class clsLoginScreen : protected clsScreen
{
private:
    static bool _Login()
    {
        short FieldLoginCount = 0;
        bool LoginFaild = false;
        string Username, Password;
        do
        {
            if (FieldLoginCount == 3)
            {
                cout << "\nYou are locked after 3 faild traills";
                return false;
            }
            if (LoginFaild)
            {
                cout << "\nInvlead Usearname/Pasword";
                cout << "\nYou have " <<3-  FieldLoginCount << " treais to login.";
            }

            cout << "\nEntear Usernaem: ";
            cin >> Username;

            cout << "\nEnter Password: ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);
            LoginFaild = CurrentUser.IsEmpty();
            FieldLoginCount++;

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;

    }
public:
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t\     Login Screen");
        return _Login();
    }
};

