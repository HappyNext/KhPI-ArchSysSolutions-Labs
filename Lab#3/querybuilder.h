#ifndef QUERYBUILDER_H
#define QUERYBUILDER_H

#include <string>

class QueryBuilder
{
    public:
        virtual QueryBuilder& select(const std::string& columns) = 0;
        virtual QueryBuilder& limit(int n) = 0;
        virtual QueryBuilder& where(const std::string& condition) = 0;
        virtual std::string getSQL() const = 0;
        virtual ~QueryBuilder() = default;
};

#endif //QUERYBUILDER_H