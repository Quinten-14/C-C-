#ifndef LIST_HPP
# define LIST_HPP

class   List
{
    public:
        List(void);

        void addTask(const Task task);

        ~List(void);

    private:
        int current_index = 0;
        std::vector<Task> tasks;
};

#endif
