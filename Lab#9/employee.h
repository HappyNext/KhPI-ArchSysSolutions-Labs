#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "ivisitable.h"
#include "ivisitor.h"

class Employee : public IVisitable {
private:
    std::string m_position;
    double m_salary;
public:
    Employee(std::string pos, double sal) : m_position(std::move(pos)), m_salary(sal) {}

    const std::string& getPosition() const { return m_position; }
    double getSalary() const { return m_salary; }

    void accept(IVisitor& visitor) override { visitor.visit(*this); }
};

#endif