#ifndef TIMEPICKER_H
#define TIMEPICKER_H

#include "component.h"

class TimePicker : public Component
{
    std::vector<std::string> availableTime;
    public:
        void updateAvailableTime(const std::vector<std::string>& times)
        {
            this->availableTime = times;
            std::cout << "TimePicker: Оновлено список доступних проміжків часу." << std::endl;
        }
        void setEnabled(bool enabled) override 
        {
            if (this->isEnabled != enabled) {
                Component::setEnabled(enabled);
                std::cout << "TimePicker: Стан змінено на " << (enabled ? "активний" : "неактивний") << std::endl;
            }
        }
        void displayStatus() const override 
        {
            std::cout << std::left << std::setw(25) << "  TimePicker:";
            std::cout << "Times = " << std::setw(14) << (availableTime.empty() ? "[]" : "[...]");
            Component::displayStatus();
            std::cout << std::endl;
        }
};

#endif // TIMEPICKER_H