#include "../Bank.hpp"

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
