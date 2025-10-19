#ifndef ORDERFORMMEDIATOR_H
#define ORDERFORMMEDIATOR_H

#include "mediator.h"
#include "datepicker.h"
#include "timepicker.h"
#include "anotherrecipientcheckbox.h"
#include "recipientnameinput.h"
#include "recipientphoneinput.h"
#include "pickupcheckbox.h"
#include "addressinput.h"

class OrderFormMediator : public Mediator
{
    private:
        DatePicker* datePicker;
        TimePicker* timePicker;
        AnotherRecipientCheckBox* anotherRecipientCheckbox;
        RecipientNameInput* recipientNameInput;
        RecipientPhoneInput* recipientPhoneInput;
        PickUpCheckBox* pickupCheckbox;
        AddressInput* addressInput;
    public:
        void setComponents(DatePicker* dp, TimePicker* tp, AnotherRecipientCheckBox* arc,
                       RecipientNameInput* rni, RecipientPhoneInput* rpi,
                       PickUpCheckBox* pc, AddressInput* ai) {
        datePicker = dp; timePicker = tp; anotherRecipientCheckbox = arc;
        recipientNameInput = rni; recipientPhoneInput = rpi; pickupCheckbox = pc; addressInput = ai;
        }

        void notify(Component* sender, const std::string& event) override
        {
            if (event == "date_changed") 
            {
                std::cout << "[Посередник]: Дата змінилася. Оновлюю доступний час..." << std::endl;
                timePicker->updateAvailableTime({"10:00 - 12:00", "14:00 - 16:00"});
            }
            
            if (event == "another_recipient_checked") 
            {
                std::cout << "[Посередник]: Статус 'інший отримувач' змінився. Показую/ховаю поля..." << std::endl;
                recipientNameInput->setVisible(anotherRecipientCheckbox->getChecked());
                recipientPhoneInput->setVisible(anotherRecipientCheckbox->getChecked());
            }

            if (event == "pickup_checked") 
            {
                std::cout << "[Посередник]: Статус 'самовивіз' змінився. Змінюю активність полів доставки..." << std::endl;
                bool isPickup = pickupCheckbox->isChecked;
                datePicker->setEnabled(!isPickup);
                timePicker->setEnabled(!isPickup);
                addressInput->setEnabled(!isPickup);
            }
        }
};

#endif // ORDERFORMMEDIATOR_H