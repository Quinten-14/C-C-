#include "./main.h"

int main(void)
{
    List    toDoList;

    std::cout << "Enter the command that you want to execute: 'ADD', 'DONE', 'VIEW' or 'EXIT'" << std::endl;

    std::string input = "";
    while (input.compare("EXIT"))
    {
        // Input handling
        std::cout << "> " << std::flush;
        std::cin >> input;
    }
    return 0;
}
