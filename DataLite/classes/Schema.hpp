#ifndef SCHEMA_HPP
# define SCHEMA_HPP

#include "Table.hpp"
#include <istream>
#include <memory>
#include <iostream>
#include <unordered_map>

class   Schema {
    public:
        Schema() = default;

        void    addTable(const std::string& tableName, std::unique_ptr<Table> table);

        Table*  getTable(const std::string& tableName) const;

        void    serialize(std::ostream& os) const;

        void    deserialize(std::istream& is);

    private:
        std::unordered_map<std::string, std::unique_ptr<Table>> m_tables;
};

#endif
