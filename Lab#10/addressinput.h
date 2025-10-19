#ifndef ADDRESSINPUT_H
#define ADDRESSINPUT_H

#include "component.h"

class AddressInput : public Component
{
    public:
        void setEnabled(bool enabled) override 
        {
            if (this->isEnabled != enabled) 
            {
                Component::setEnabled(enabled);
                std::cout << "AddressInput: Стан змінено на " << (enabled ? "активний" : "неактивний") << std::endl;
            }
        }
        void displayStatus() const override 
        {
            std::cout << std::left << std::setw(25) << "  AddressInput:";
            std::cout << std::setw(22) << " ";
            Component::displayStatus();
            std::cout << std::endl;
        }
};

#endif // ADDRESSINPUT_H