#ifndef USERINPUT_H
#define USERINPUT_H

#include <string>
#include <iostream>
#include <sstream>

// Function template declaration and definition
template<typename T>
void GetUserInput(const std::string& InputPrompt, T& VarToChange) {
    while (true) {
        std::cout << InputPrompt;
        std::string Fetchedline;
        if (!std::getline(std::cin, Fetchedline) || Fetchedline.empty()) {
            if (std::cin.eof()) {
                std::cout << "\nExiting\n";
                std::exit(EXIT_SUCCESS);
            }
            std::cin.clear();
            std::cout << "Invalid input. Please try again.\n";
            continue;
        }

        std::istringstream iss(Fetchedline);
        if (iss >> VarToChange) {
            char leftover;
            if (!(iss >> leftover)) {
                break;
            }
        }
        std::cout << "Invalid input. Please try again.\n";
    }
}

#endif // USERINPUT_H
