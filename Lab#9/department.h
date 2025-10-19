#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <vector>
#include <memory>
#include <string>
#include "employee.h"   // <-- ОСЬ ЦЕ РІШЕННЯ
#include "ivisitable.h" // та інші необхідні заголовки

class Department : public IVisitable {
private:
    std::string m_name;
    std::vector<std::unique_ptr<Employee>> m_employees;
public:
    Department(std::string n, std::vector<std::unique_ptr<Employee>> emps)
        : m_name(std::move(n)), m_employees(std::move(emps)) {}

    const std::string& getName() const { return m_name; }
    const std::vector<std::unique_ptr<Employee>>& getEmployees() const { return m_employees; }

    void accept(IVisitor& visitor) override {
        visitor.visit(*this);
        for (const auto& emp : m_employees) {
            emp->accept(visitor);
        }
    }
};

#endif // DEPARTMENT_H