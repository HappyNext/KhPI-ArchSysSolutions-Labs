#include <iostream>
#include <clocale>
#include "Windows.h"
#include "company.h"
#include "salaryreportvisitor.h"

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    std::vector<std::unique_ptr<Employee>> dev_employees;
    dev_employees.push_back(std::make_unique<Employee>("Senior C++ Developer", 140000.00));
    dev_employees.push_back(std::make_unique<Employee>("Middle Go Developer", 110000.00));

    std::vector<std::unique_ptr<Employee>> hr_employees;
    hr_employees.push_back(std::make_unique<Employee>("HR Manager", 35000.00));

    std::vector<std::unique_ptr<Department>> all_departments;
    all_departments.push_back(std::make_unique<Department>("Розробки", std::move(dev_employees)));
    all_departments.push_back(std::make_unique<Department>("HR та Рекрутинг", std::move(hr_employees)));
    
    Company company("Global Tech Innovations", std::move(all_departments));

    std::cout << ">>> ЗВІТ ДЛЯ ВСІЄЇ КОМПАНІЇ:\n";
    SalaryReportVisitor company_visitor;
    company.accept(company_visitor);
    std::cout << company_visitor.getReport() << std::endl;

    return 0;
}