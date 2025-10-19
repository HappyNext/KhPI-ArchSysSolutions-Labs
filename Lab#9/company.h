#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <vector>
#include <memory>
#include "department.h"
#include "ivisitable.h"

class Company : public IVisitable {
private:
    std::string m_name;
    std::vector<std::unique_ptr<Department>> m_departments;
public:
    Company(std::string n, std::vector<std::unique_ptr<Department>> deps)
        : m_name(std::move(n)), m_departments(std::move(deps)) {}

    const std::string& getName() const { return m_name; }
    const std::vector<std::unique_ptr<Department>>& getDepartments() const { return m_departments; }

    void accept(IVisitor& visitor) override {
        visitor.visit(*this);
        for (const auto& dep : m_departments) {
            dep->accept(visitor);
        }
    }
};

#endif // COMPANY_H