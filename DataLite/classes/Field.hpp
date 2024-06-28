#ifndef FIELD_HPP
#define FIELD_HPP

#include <string>
#include <iostream>
#include <vector>
#include <memory>


struct Field {
    std::string name;
    int value;

    Field(const std::string& name, int value) : name(name), value(value) {}
};

#endif
