#include "./Bank.hpp"

int main(void)
{
    UserAccount account;

    AccountHandler(account);
    SessionLoop(account);
    account.UpdateAccountFileData();
}
