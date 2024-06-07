#ifndef USERACCOUNT_HPP
# define USERACCOUNT_HPP

class   UserAccount
{
    public:
        void SetupAccount();

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
        bool    EmailAlreadyExistsChecker(std::string& email);
        int     GetUniqueUserID();
};

#endif
