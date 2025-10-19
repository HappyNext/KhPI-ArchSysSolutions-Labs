#ifndef IVISITOR_H
#define IVISITOR_H

class Employee;
class Department;
class Company;

class IVisitor {
public:
    virtual void visit(Company& company) = 0;
    virtual void visit(Department& department) = 0;
    virtual void visit(Employee& employee) = 0;
    ~IVisitor() = default;
};

#endif // IVISITOR_H