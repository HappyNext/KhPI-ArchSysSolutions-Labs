#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <iomanip>
#include <vector>
#include "mediator.h"

class Component
{
    protected:
        Mediator* dialog;
        bool isVisible = true;
        bool isEnabled = true;
    public:
        Component(Mediator* d = nullptr): dialog(d) {}
        virtual ~Component() = default;
        void setMediator(Mediator* m) { this->dialog = m; }
        virtual void setVisible(bool visible) { this->isVisible = visible;}
        virtual void setEnabled(bool enabled) { this->isEnabled = enabled;}
        virtual void displayStatus() const {
            std::cout << ", isVisible = " << std::boolalpha << isVisible
                      << ", isEnabled = " << std::boolalpha << isEnabled;
        }
};

#endif // COMPONENT_H