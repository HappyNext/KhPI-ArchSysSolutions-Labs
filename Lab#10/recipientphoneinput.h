#ifndef RECIPIENTPHONEINPUT_H
#define RECIPIENTPHONEINPUT_H

#include "component.h"

class RecipientPhoneInput : public Component
{
    public:
        RecipientPhoneInput() { this->isVisible = false; }

        void setVisible(bool visible) override 
        {
            if (this->isVisible != visible) 
            {
                Component::setVisible(visible);
                std::cout << "RecipientPhoneInput: Поле стало " << (visible ? "видимим" : "невидимим") << std::endl;
            }
        }
        void displayStatus() const override 
        {
            std::cout << std::left << std::setw(25) << "  RecipientPhoneInput:";
            std::cout << std::setw(22) << " ";
            Component::displayStatus();
            std::cout << std::endl;
        }
};

#endif // RECIPIENTPHONEINPUT_H