#ifndef SALARYREPORTVISITOR_H
#define SALARYREPORTVISITOR_H

#include "ivisitor.h"
#include "company.h"
#include "department.h"
#include "employee.h"

class SalaryReportVisitor : public IVisitor {
private:
    std::string report_content;
    double total_salary = 0.0;
public:
    void visit(Employee& employee) override {
        char buffer[128];
        snprintf(buffer, sizeof(buffer), "  - %s: %.2f грн\n",
                 employee.getPosition().c_str(), 
                 employee.getSalary());          
        report_content += buffer;
        total_salary += employee.getSalary();
    }
    void visit(Department& department) override {
        report_content += "\n--- Департамент: '" + department.getName() + "' ---\n";
    }
    void visit(Company& company) override {
        report_content = "ЗАРПЛАТНА ВІДОМІСТЬ ПО КОМПАНІЇ '" + company.getName() + "'\n" + std::string(40, '=') + "\n";
    }
    std::string getReport() 
    { 
        char buffer[128];
        snprintf(buffer, sizeof(buffer), "\n%s\nЗАГАЛЬНА СУМА: %.2f грн", std::string(30, '=').c_str(), total_salary);
        return report_content + buffer;
    }
};

#endif // SALARYREPORTVISITOR_H