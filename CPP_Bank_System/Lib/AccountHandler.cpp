#include "../Bank.hpp"
#include "UserInput.h"

void    AccountHandler(UserAccount account)
{
    std::string input;

    while (input.compare("EXIT"))
    {
        GetUserInput("Do you want to 'LOGIN' or 'SIGNUP': ", input);
        if (input.compare("SIGNUP") == 0)
        {
            account.SetupAccount();
            return;
        }
        else if (input.compare("LOGIN") == 0)
        {
            account.LoginLogic();
            return;
        }
    }
}
