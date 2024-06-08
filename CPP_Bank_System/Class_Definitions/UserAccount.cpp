#include "../Bank.hpp"
#include <utility>

bool UserAccount::EmailAlreadyExistsChecker(std::string& email)
{
    std::ifstream file("Data/UserAccounts.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream FoundEmail(line);
            int id;
            std::string fullName, userEmail, userPassword;
            double moneyBalance;
            FoundEmail >> id >> fullName >> userEmail >> userPassword >> moneyBalance;
            if (userEmail == email) {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

void UserAccount::GetEmailUserInput()
{
    while (true)
    {
        GetUserInput("Enter Your Email: ", this->m_UserEmail);
        if (!EmailAlreadyExistsChecker(this->m_UserEmail))
            break;
        else
            std::cout << "Email Already Exists. Enter A Different One" << std::endl;
    }
}

void UserAccount::GetSignUpInfo()
{
    GetUserInput("Enter Your Full Name: ", this->m_FullName);
    GetEmailUserInput();
    GetUserInput("Enter Your Password: ", this->m_UserPassword);
}

int UserAccount::GetUniqueUserID()
{
    int highestID = -1;
    std::ifstream file("Data/UserAccounts.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream FoundId(line);
            int id;
            FoundId >> id;
            if (id > highestID)
                highestID = id;
        }
        file.close();
        return (highestID + 1);
    }
    else
        return 0;
}

void UserAccount::SaveAccountToFile()
{
    std::ofstream file("Data/UserAccounts.txt", std::ios_base::app);
    if (file.is_open())
        file << this->m_UserID << " " << this->m_FullName << " " << this->m_UserEmail << " " << this->m_UserPassword << " " << this->m_MoneyBalance << std::endl;
    else
    {
        std::cerr << "Failed top open accounts file for writing" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void UserAccount::SetupAccount()
{
    GetSignUpInfo();
    this->m_UserID = GetUniqueUserID();
    this->m_MoneyBalance = 0;
    SaveAccountToFile();
}

std::pair<std::string, std::string> UserAccount::GetLoginCredentials()
{
    std::string email;
    std::string password;
    GetUserInput("Enter Your Email: ", email);
    GetUserInput("Enter Your Password: ", password);
    return std::make_pair(email, password);
}

void UserAccount::AttemptLogin(const std::pair<std::string, std::string>&credentials)
{
    const std::string email = credentials.first;
    const std::string password = credentials.second;

    std::ifstream file("Data/UserAccounts.txt");
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream accountInfo(line);
            int id;
            std::string fullName, userEmail, userPassword;
            double moneyBalance;
            accountInfo >> id >> fullName >> userEmail >> userPassword >> moneyBalance;
            if (userEmail == email && userPassword == password)
            {
                std::cout << "Login successful!" << std::endl;
                // Load user account data if needed
                this->m_UserID = id;
                this->m_FullName = fullName;
                this->m_UserEmail = userEmail;
                this->m_UserPassword = userPassword;
                this->m_MoneyBalance = moneyBalance;
                return;
            }
        }
        file.close();
    }
    else
    {
        std::cerr << "Failed to open accounts file for reading" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void UserAccount::LoginLogic()
{
    int RemainingAttempts = 3;
    while (RemainingAttempts > 0)
    {
        auto credentials = GetLoginCredentials();
        AttemptLogin(credentials);
        if (!this->m_UserID)
            return;
        RemainingAttempts--;
        if (RemainingAttempts != 0)
            std::cout << "Wrong Email or Password. You have " << RemainingAttempts << " attempts left" << std::endl;
        else
            std::cout << "You reached the max login tries." << std::endl;
    }
}
