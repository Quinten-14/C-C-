#include "../Bank.hpp"
#include <ios>
#include <limits>

Account::Account(void)
{
    this->m_createDate = std::time(nullptr);
    if (DEBUG_MODE == true)
        std::cout << "Time Account Was Created: " << ctime(&this->m_createDate) << std::endl;
}

void    Account::CreateAccount(void)
{
    // TODO: Take the first available ID
    this->m_id = 0;

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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    this->m_balance = 0;
    this->m_accountNumber = 0; // Placeholder for now
    // TODO: Accounts should be saved to a file for use on next runtime
}
