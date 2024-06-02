#ifndef TASK_HPP
# define TASK_HPP

class   Task
{
    public:
        Task(void);

        void newTask(void);

        ~Task(void);

    private:
        int m_id;
        std::string m_name;
        std::string m_bio;
        bool m_completed;
        std::string m_dueData;
};

#endif
