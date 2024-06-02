#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

class   Account
{
    public:
        // Constructor
        Account(void);

        void    CreateAccount(void);

        void    DebugView(void);

    // General Data structure for accounts
    private:
        int     m_id;
        int     m_accountNumber;
        double  m_balance;
        std::time_t m_createDate;
        std::string m_email;
        std::string m_fullName;
        std::string m_password; // Later should be hashed so it's safe
};

#endif
