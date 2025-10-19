#ifndef ANOTHERRECIPIENTCHECKBOX_H
#define ANOTHERRECIPIENTCHECKBOX_H

#include "component.h"

class AnotherRecipientCheckBox : public Component
{
    bool isChecked = false;
    public:
        void check(bool checked) 
        {
            this->isChecked = checked;
            std::cout << "AnotherRecipientCheckbox: стан змінено на " << std::boolalpha << this->isChecked << std::endl;
            dialog->notify(this, "another_recipient_checked");
        }
        void displayStatus() const override 
        {
            std::cout << std::left << std::setw(25) << "  AnotherRecipientChk:"
                    << "isChecked = " << std::setw(10) << std::boolalpha << isChecked;
            Component::displayStatus();
            std::cout << std::endl;
        }
        bool getChecked()
        {
            return isChecked;
        }
};

#endif // ANOTHERRECEPIENTCHECKBOX_H