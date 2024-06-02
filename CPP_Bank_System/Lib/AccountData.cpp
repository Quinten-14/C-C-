#include "../Bank.hpp"

// Function that is called and will then see if you want to login or create a new account
void    AccountHandler(void)
{
    std::cout << "Do you want to sign in or create an account. Input 'SIGNUP', 'SIGNIN' or 'EXIT'" << std::endl;
    
    std::string input = "";
    while (input.compare("EXIT"))
    {
        if (std::cin.eof())
        {
            std::cout << "\nExiting\n";
            std::exit(EXIT_SUCCESS);
        }

        if (input.compare("SIGNUP") == 0)
        { 
            Account account;

            account.CreateAccount();

            account.DebugView();
            break;
        }
        else if (input.compare("SIGNIN") == 0)
        {
            std::cout << "Signin Called" << std::endl;
            break;
        }
        std::cout << "> " << std::flush;
        std::cin >> input;
    }
}
