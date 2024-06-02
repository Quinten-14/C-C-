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

    auto getInput = [](const std::string& prompt, std::string& input) {
        while (true) {
            std::cout << prompt;
            if (!std::getline(std::cin, input) || input.empty()) {
                if (std::cin.eof()) {
                    std::cout << "\nExiting\n";
                    std::exit(EXIT_SUCCESS);
                }
                std::cin.clear();
                std::cout << "Invalid input. Please try again.\n";
            } else {
                break;
            }
        }
    };

    getInput("Enter Full Name: ", this->m_fullName);
    getInput("Enter Email: ", this->m_email);
    getInput("Enter Password: ", this->m_password);

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
