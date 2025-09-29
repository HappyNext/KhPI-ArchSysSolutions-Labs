#ifndef MYSQLBUILDER_H

#include "querybuilder.h"
#include <sstream>

class MySQLBuilder : public QueryBuilder
{
    std::string _select;
    std::string _where;
    std::string _limit;
    public:
        QueryBuilder& select(const std::string& columns) override 
        {
            _select = "SELECT " + columns;
            return *this;
        }

        QueryBuilder& where(const std::string& condition) override 
        {
            _where = "WHERE " + condition;
            return *this;
        }

        QueryBuilder& limit(int n) override 
        {
            _limit = "LIMIT " + std::to_string(n);
            return *this;
        }

        std::string getSQL() const override 
        {
            std::ostringstream query;
            query << _select << " " << _where << " " << _limit << ";";
            return query.str();
        }
};

#endif // MYSQLBUILDER_H