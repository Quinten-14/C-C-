#ifndef BANK_HPP
# define BANK_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <sstream>

#include "./Lib/UserInput.h"

// Custom Classes
#include "./Class/UserAccount.hpp"

// Functions
void    AccountHandler(UserAccount account);
void    SessionLoop(UserAccount account);

#endif
