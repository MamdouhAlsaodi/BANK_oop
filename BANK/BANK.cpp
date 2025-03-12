#include <iostream>
#include "clsLoginScreen.h"
#include "clsUser.h"
#include "clsUtil.h"
int main()
{
    //cout <<clsUtil::EncryptText("M9695") << endl;
    //cout <<clsUtil::EncryptText("M102") << endl;
    //cout <<clsUtil::EncryptText("M1911") << endl;
    while(true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
            break;
    }
    system("pause>0");
    return 0;
}