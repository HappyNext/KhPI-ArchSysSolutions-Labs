#ifndef PICKUPCHECKBOX_H
#define PICKUPCHECKBOX_H

#include "component.h"

class PickUpCheckBox : public Component
{
    public:
        bool isChecked = false;
        void check(bool checked) 
        {
            this->isChecked = checked;
            std::cout << "PickupCheckbox: стан змінено на " << std::boolalpha << this->isChecked << std::endl;
            dialog->notify(this, "pickup_checked");
        }
        
        void displayStatus() const override 
        {
            std::cout << std::left << std::setw(25) << "  PickupCheckbox:"
                    << "isChecked = " << std::setw(10) << std::boolalpha << isChecked;
            Component::displayStatus();
            std::cout << std::endl;
        }
};

#endif // PICKUPCHECKBOX_H