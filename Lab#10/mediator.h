#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>

class Component;

class Mediator
{
    public:
        virtual void notify(Component* sender, const std::string& event) = 0;
        ~Mediator() = default;
};

#endif // MEDIATOR_H