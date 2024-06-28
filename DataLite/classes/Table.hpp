#ifndef TABLE_HPP
# define TABLE_HPP

#include "./Record.hpp"
#include <iostream>
#include <memory>

class   Table {
    public:
        Table() = default;

        // Record Setter
        void    addRecord(std::unique_ptr<Record> record);

        // Record Getter
        const std::vector<std::unique_ptr<Record>>& getRecord() const;

        void    serialize(std::ostream& os) const;

        void    deserialize(std::istream& is);

    private:
        std::vector<std::unique_ptr<Record>> m_records;
};

#endif
