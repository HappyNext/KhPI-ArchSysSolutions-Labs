#include <iostream>
#include "postgresqlbuilder.h"
#include "mysqlbuilder.h"

int main()
{
    // PostgreSQL
    PostgreSQLBuilder pgBuilder;
    std::string pgQuery = pgBuilder
        .select("*")
        .where("age > 18")
        .limit(10)
        .getSQL();
    std::cout << "PostgreSQL query: " << pgQuery << std::endl;

    // MySQL
    MySQLBuilder myBuilder;
    std::string myQuery = myBuilder
        .select("name, email")
        .where("status = 'active'")
        .limit(5)
        .getSQL();
    std::cout << "MySQL query: " << myQuery << std::endl;

    return 0;
}