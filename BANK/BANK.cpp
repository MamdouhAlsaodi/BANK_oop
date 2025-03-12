#include <iostream>
#include "clsLoginScreen.h"
#include "clsUser.h"
#include "clsUtil.h"
int main()
{

    while(true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
            break;
    }
    system("pause>0");
    return 0;
}
