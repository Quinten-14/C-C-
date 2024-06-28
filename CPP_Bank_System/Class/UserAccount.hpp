#ifndef USERACCOUNT_HPP
# define USERACCOUNT_HPP

class   UserAccount
{
    public:
        void SetupAccount();
        void LoginLogic();
        void DepositMoney();
        void WithdrawMoney();
        void UpdateAccountFileData();

    private:
        std::string m_FullName;
        std::string m_UserEmail;
        std::string m_UserPassword;
        double m_MoneyBalance;
        int m_UserID;

    private:
        void    GetSignUpInfo();
        void    SaveAccountToFile();
        void    GetEmailUserInput();
        std::pair<std::string, std::string>GetLoginCredentials();
        void    AttemptLogin(const std::pair<std::string, std::string>& credentials);
        bool    EmailAlreadyExistsChecker(std::string& email);
        int     GetUniqueUserID();
};

#endif
