#ifndef DATAPICKER_H
#define DATAPICKER_H

#include "component.h"

class DatePicker : public Component
{
    std::string selectedDate = "Not Selected";
    public:
        void selectDate(const std::string& date)
        {
            this->selectedDate = date;
            std::cout << "DatePicker: Обрано дату - " << date << std::endl;
            dialog->notify(this, "date_changed");
        }

        void setEnabled (bool enabled) override
        {
            if (this->isEnabled != enabled)
            {
                Component::setEnabled(enabled);
                std::cout << "DatePicker: Стан змінено на " << (enabled ? "активний" : "неактивний") << std::endl;
            }
        }
        void displayStatus() const override 
        {
            std::cout << std::left << std::setw(25) << "  DatePicker:" 
                      << "Date = " << std::setw(15) << selectedDate;
            Component::displayStatus();


            std::cout << std::endl;
        }
};

#endif // DATAPICKER_H