#ifndef RECORD_HPP
# define RECORD_HPP

#include "Field.hpp"
#include <unordered_map>
#include <string>
#include <memory>

class   Record {
    public:
        Record() = default;
        void    setValue(const std::string& fieldName, int value);
        void    serialize(std::ostream& os) const;
        void    deserialize(std::istream& is);

    private:
        std::unordered_map<std::string, std::unique_ptr<Field>> m_data;
};

#endif
