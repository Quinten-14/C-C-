#ifndef TRANSACTION_HPP
# define TRANSACTION_HPP

class  Transaction
{
    public:

    private:
        int     m_id;
        int     m_from;
        int     m_to;
        double  m_amount;
        std::string m_message;
        std::time_t m_transactionDate;
};

#endif
