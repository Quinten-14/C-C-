#include "../Bank.hpp"

Account::Account(void)
{
}

// Todo list:
// - Adding check for dup emails
// - Hash Password

void    Account::CreateAccount(void)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // TODO: Take the first available ID
    this->m_id = 0;

    this->m_createDate = std::time(nullptr);

    // This whole thing with while loops seems very verbose so currently thinking of a better way
    while (true)
    {
        std::cout << "Enter Your Full Name: ";
        if (!std::getline(std::cin, this->m_fullName) || this->m_fullName.empty())
        {
            if (std::cin.eof())
            {
                std::cout << "\nExiting\n";
                std::exit(EXIT_SUCCESS);
            }
            std::cin.clear();
            std::cout << "Invalid Input. Input Can't Be Empty\n";
        }
        else
            break;
    }

    while (true)
    {
        std::cout << "Enter Your Email: ";
        if (!std::getline(std::cin, this->m_email) || this->m_email.empty())
        {
            if (std::cin.eof())
            {
                std::cout << "\nExiting\n";
                std::exit(EXIT_SUCCESS);
            }
            std::cin.clear();
            std::cout << "Invalid Input. Input Can't Be Empty\n";
        }
        else
            break;
    }

    while (true)
    {
        std::cout << "Enter Your Password: ";
        if (!std::getline(std::cin, this->m_password) || this->m_password.empty())
        {
            if (std::cin.eof())
            {
                std::cout << "\nExiting\n";
                std::exit(EXIT_SUCCESS);
            }
            std::cin.clear();
            std::cout << "Invalid Input. Input Can't Be Empty\n";
        }
        else
        {
            break;
        }
    }

    this->m_balance = 0;
    this->m_accountNumber = 0; // Placeholder for now
    // TODO: Accounts should be saved to a file for use on next runtime
}

void    Account::DebugView(void)
{
    std::cout << "\n<----- Debug View ----->\n" << std::endl;
    std::cout << "Account ID: " << this->m_id << std::endl;
    std::cout << "Full Name: " << this->m_fullName << std::endl;
    std::cout << "Email: " << this->m_email << std::endl;
    std::cout << "Password: " << this->m_password << std::endl;
    std::cout << "Balance: " << this->m_balance << std::endl;
    std::cout << "Account Create Date: " << ctime(&this->m_createDate) << std::flush;
    std::cout << "Account Number: " << this->m_accountNumber << std::endl;
    std::cout << "\n<----- Debug View ----->\n" << std::endl;
}
