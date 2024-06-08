#include "../Bank.hpp"
#include "UserInput.h"

void SessionLoop(UserAccount account)
{
    std::string input;
    std::cout << "\nWhich command do you want to do\n" << std::endl;
    std::cout << "DEPOSIT\nWITHDRAW\nTRANSFER\nEXIT\n" << std::endl;
    while (input.compare("EXIT"))
    {
        GetUserInput("Choice> ", input);
        if (!input.compare("DEPOSIT"))
            account.DepositMoney();
        else if (!input.compare("WITHDRAW"))
            account.WithdrawMoney();
    }
}
