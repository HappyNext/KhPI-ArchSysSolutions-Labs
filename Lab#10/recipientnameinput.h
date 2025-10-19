#ifndef RECIPIENTNAMEINPUT_H
#define RECIPIENTNAMEINPUT_H

#include "component.h"

class RecipientNameInput : public Component
{
    public:
        RecipientNameInput() { this->isVisible = false; }
        void setVisible(bool visible) override 
        {
            if (this->isVisible != visible) 
            {
                Component::setVisible(visible);
                std::cout << "RecipientNameInput: Поле стало " << (visible ? "видимим" : "невидимим") << std::endl;
            }
        }
        void displayStatus() const override 
        {
            std::cout << std::left << std::setw(25) << "  RecipientNameInput:";
            std::cout << std::setw(22) << " ";
            Component::displayStatus();
            std::cout << std::endl;
        }
};

#endif // RECEPIENTNAMEINPUT_H