#include "../Bank.hpp"
#include <cstdlib>
#include <fstream>
#include <ios>
#include <ostream>
#include <sstream>

Account::Account(void)
{
}

// Todo list:
// - Adding check for dup emails
// - Hash Password
// - Get right ID's
// - Get original Account Number
// - Save Accounts to a file

void    Account::CreateAccount(void)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Find a way to do it without this

    this->m_id = Account::getNextId();

    this->m_createDate = std::time(nullptr);

    // Is somewhat portable but don't really like the auto keyword (might take a look at it later)
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
    this->m_accountNumber = 0;
    Account::saveAccount();
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

// Not yet sure if this is the final way i want it
void    Account::saveAccount(void) const
{
    std::ofstream file("Data/Accounts.txt", std::ios_base::app);
    if (file.is_open())
        file << m_id << " " << m_accountNumber << " " << m_balance << " " << m_createDate << " " << m_email << " " << m_fullName << " " << m_password << std::endl;
    else
    {
        std::cerr << "Failed to open accounts file for writing" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

// works for now
int     Account::getNextId(void)
{
    int highestID = -1;

    std::ifstream file("Data/Accounts.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int id;
            iss >> id;
            if (id > highestID) {
                highestID = id;
            }
        }
        file.close();
    }
    else
        return 0;
    return (highestID + 1);
}
